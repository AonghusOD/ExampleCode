 //Maybe use time dispaly task with PIT for 10b
//Was working on using software timer to increment seconds

/**
 * @file    TAD_Project_Template.c
 * @brief   Application entry point.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
//#include <ArduinoJson.h>

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "ESP8266.h"
#include "client.h"
#include "MQTT_client.h"


typedef struct {
	uint8_t idNumber;
	uint32_t qData;
} publishStruct;

#define TimeDisplay_ID 0
#define SW2_ID 1
#define SW3_ID 2
#define LED_ID 3
#define OPD_ID 4
uint32_t timeSeconds = 0;


/*
 * The following block is used for real time debugging statistics
 * DO NOT CHANGE THIS CODE
 * should have code broken down into files
 * What core put devices
 * Work out how much stack memory eqach task would need
 * How schedule 1 task to run once per day|Best way to power save
 * Check pins to see power usage
 * How to parse JSON File
 * What should focus on
 * Just one task managing everything createing deleting,
 * Disregard zeros
 *
 * To Disable real time statistics
 * 1. Disable the FTM0 peripheral using the Peripherals Config tool
 * 2. Change configGENERATE_RUN_TIME_STATS define to 0 in FreeRTOSConfig.h
 */
static uint32_t RTOS_RunTimeCounter;  //runtime counter, used for configGENERATE_RUNTIME_STATS

void FTM0_IRQHandler(void) {

   //Clear interrupt flag.

  FTM_ClearStatusFlags(FTM0, kFTM_TimeOverflowFlag);

  RTOS_RunTimeCounter++;  //increment runtime counter
}

void RTOS_AppConfigureTimerForRuntimeStats(void) {

  RTOS_RunTimeCounter = 0;

  NVIC_SetPriority(FTM0_IRQn, 2);
  EnableIRQ(FTM0_IRQn);
}

uint32_t RTOS_AppGetRuntimeCounterValueFromISR(void) {

  return RTOS_RunTimeCounter;
}
/*
 * End of real time statistics code
 */

/* TODO: insert other definitions and declarations here */
void initTask(void *pvParameters);
void publishTask(void *pvParameters);
void sw2_Task(void *pvParameters);
void subscribeTask(void *pvParameters);
void timeDisplayTask(void *pvParameters);
void setTimeTask(void *pvParameters);
void SW3_Display(void *pvParameters);
void oncePerDayTask(void *pvParameters);
//void semGive(void *pvParameters);
QueueHandle_t data_Queue = NULL;

TaskHandle_t timeDisplayTaskHandle = NULL;

SemaphoreHandle_t SW2_Semaphore = NULL;

SemaphoreHandle_t wait_Semaphore = NULL;
SemaphoreHandle_t PIT_Semaphore = NULL;


TimerHandle_t AutoReloadTimerHandle = NULL;
void AutoReloadCallback(TimerHandle_t xTimer);


/*
 * @brief   Application entry point.
 */


/* UART0_RX_TX_IRQn interrupt handler */
void UART0_SERIAL_RX_TX_IRQHANDLER(void) {
	static BaseType_t xHigherPriorityTaskWoken;
	uint32_t intStatus;
	uint8_t ch = 0;
	//create buffer //static only initslise first time interrupt runs
	static char userTime[10] = "0", temp[3] = "0";
	static uint8_t x = 0;
	static uint32_t totalSeconds = 0;

  /* Reading all interrupt flags of status registers */
  intStatus = UART_GetStatusFlags(UART0_PERIPHERAL);

  /* Flags can be cleared by reading the status register and reading/writing data registers.
    See the reference manual for details of each flag.
    The UART_ClearStatusFlags() function can be also used for clearing of flags in case the content of data regsiter is not used.
    For example:
        status_t status;
        intStatus &= ~(kUART_RxOverrunFlag | kUART_NoiseErrorFlag | kUART_FramingErrorFlag | kUART_ParityErrorFlag);
        status = UART_ClearStatusFlags(UART0_PERIPHERAL, intStatus);
  */

  /* Place your code here */
   	  userTime[x] = UART_ReadByte(UART0);
   	  //wait for carriage return
   	  if(userTime[x] == '\r'){
   		  //calculate time in seconds
   		  temp[0] = userTime[0];
   		  temp[1] = userTime[1];
   		  totalSeconds = atoi(temp) * 3600;  //hours
   		  temp[0] = userTime[3];
   		  temp[1] = userTime[4];
   		  totalSeconds += atoi(temp) * 60;  // hours + minutes
   		  temp[0] = userTime[6];
   		  temp[1] = userTime[7];
   		  totalSeconds += atoi(temp);  //hours + minutes + seconds

   		  //notify time display
   		  if(totalSeconds < 86400){    //check if less than seconds in day
   			  xHigherPriorityTaskWoken = pdFALSE;
   			  xTaskNotifyFromISR(timeDisplayTaskHandle, totalSeconds, eSetValueWithOverwrite, &xHigherPriorityTaskWoken);
   			  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
   		  }
   		  else{
   			  printf("invalid time \n\r");
   		  }
   		  x = 0;
   		  memset(userTime, 0, sizeof(userTime));
   		  memset(temp, 0, sizeof(temp));
   	  }
   	  else{
   		  x++;
   	  }

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

int main(void) {


  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif


    xTaskCreate(initTask, "Init Task", 300, NULL, 4, NULL);

    data_Queue = xQueueCreate(5, sizeof(publishStruct));
    vQueueAddToRegistry(data_Queue, "Data Queue"); // just for debug

    AutoReloadTimerHandle = xTimerCreate("Auto Reload Timer", pdMS_TO_TICKS(10000), pdTRUE, 0, AutoReloadCallback);
    xTimerStart(AutoReloadTimerHandle, 0);

    vTaskStartScheduler();

    while(1) {
    }
    return 0 ;
}

void initTask(void *pvParameters) {
	char ID[9];
	printf("Starting Task 1\n\r");
    while(1) {
    	if(espSendATCommand(AT, OK_Response, 2000) == TIMEOUT) {
    		printf("\n\r**** No Response, Check ESP8266 Connections\n\r");
    	}
    	else
    		break;
    }

    //Configure ESP8266 in station mode
    espSendATCommand(modeSetStation, OK_Response, 2000);
    //List available WiFi access points
    espSendATCommand(listAPs, OK_Response, 20000);

    //Connect to WiFi access points
    //Enter your WiFi access point SSID and password here
    espAPConnect("GalaxyS", "k2bh7262");

    //Create a unique client ID based on micro ID
    memset(ID, 0, sizeof(ID));
    itoa(SIM->UIDL, ID, 10);

    //Connect to MQTT brokerv
    if(Client_Connect("io.adafruit.com", ID, 1, "aodomh", "aio_oJCj08heegdEawWeaD99RcBg5s3X") == MQTT_CONNECT_OK) {
    	printf("\n\n\rConnected to MQTT Broker, creating publish topic\n\n\r");
    	xTaskCreate(publishTask, "Publish Task", 300, NULL, 4, NULL);
    	xTaskCreate(sw2_Task, "SW2 Task", 100, NULL, 4, NULL);
    	xTaskCreate(subscribeTask, "Subscribe Task", 300, NULL, 4, NULL);
    	//xTaskCreate(semGive, "Subscribe Task", 300, NULL, 4, NULL);
    	xTaskCreate(setTimeTask, "Set Time Task", 300, NULL, 3, &timeDisplayTaskHandle);
    	xTaskCreate(SW3_Display, "SW3 Display", 100, NULL, 4, NULL);
    	xTaskCreate(oncePerDayTask, "OPD Task", 100, NULL, 4, NULL);
    	SW2_Semaphore = xSemaphoreCreateBinary();
    	wait_Semaphore = xSemaphoreCreateBinary();
    	PIT_Semaphore = xSemaphoreCreateBinary();
    	vTaskDelete(NULL);
    }
    else {
    	printf("\n\n\rCould nor connect to MQTT broker, stopping application\n\n\r");
    	while(1);
    }

	while(1) {
	}
}

/*
Poll SW2 every 100ms and send semaphore to publish task when switch is pressed
*/
void sw2_Task(void *pvParameters) {
	publishStruct SW2_data;
	while(1) {
		if(xSemaphoreTake(wait_Semaphore,  portMAX_DELAY) == pdTRUE){
		if(GPIO_PinRead(GPIOC, 6) == 1) {
			SW2_data.qData = rand()%51;
			SW2_data.idNumber = SW2_ID;
			xQueueSend(data_Queue, &SW2_data, 0);
			while(GPIO_PinRead(GPIOC, 6) == 1);
		}
		vTaskDelay(pdMS_TO_TICKS(1000));
		}
	}
}


/*
 * Publish to SW2 data feed when semaphore is available
 */
void publishTask(void *pvParameters) {
	while(1) {
		publishStruct received_data;
		uint32_t hour = 0, min = 0, sec = 0; //
		while(1) {
				xQueueReceive(data_Queue, &received_data, portMAX_DELAY);
				printf("Data received in queue\n\r");
				char realTime[10],hour2[2],min2[2],sec2[2];
				switch(received_data.idNumber){
				case TimeDisplay_ID:
					printf("Time Received: %lums\n\r", received_data.qData);
					hour = received_data.qData/3600;
					min = (received_data.qData%3600)/60;
					sec = received_data.qData%60;
					sprintf(hour2, "%d", hour);
					sprintf(min2, "%d", min);
					sprintf(sec2, "%d", sec);

					sprintf(realTime,"%s:%s:%s",hour2,min2,sec2);

					//Client_PublishNumberData("aodomh/feeds/sw2-data-feed", received_data.qData%60, 0);
					Client_PublishStringData("aodomh/feeds/time-display-data-field", realTime, 0);
					break;
				case SW2_ID:
					printf("Time Received: %lums\n\r", received_data.qData);
					Client_PublishNumberData("aodomh/feeds/sw2-data-feed", received_data.qData, 0);
					break;
				case SW3_ID:
					printf("Time Received: %lums\n\r", received_data.qData);
					hour = received_data.qData/3600;
					min = (received_data.qData%3600)/60;
					sec = received_data.qData%60;
					sprintf(hour2, "%d", hour);
					sprintf(min2, "%d", min);
					sprintf(sec2, "%d", sec);

					sprintf(realTime,"%s:%s:%s",hour2,min2,sec2);

					Client_PublishStringData("aodomh/feeds/time-display-data-field", realTime, 0);
					break;
				case LED_ID:
					printf("Time Received: %lums\n\r", received_data.qData);
					xSemaphoreGive(wait_Semaphore);
					char fullStr[55];
					char firstStr[15] = "Button Pressed,";
					char lastStr[30] = "Led Turned On Successfully";
					printf("Int received_data.qData = %d", received_data.qData);
					printf("String received_data.qData = %s", received_data.qData);
					if(received_data.qData == 0){
					char ledOff[10] = "LED OFF!";
					//sprintf(fullStr,"%s %s %s",firstStr,ledCol,lastStr);
					Client_PublishStringData("aodomh/feeds/led-data-feed", ledOff, 0);
					}
					if(received_data.qData == 1){
						char redCol[5] = "Red";
						sprintf(fullStr,"%s %s %s",firstStr,redCol,lastStr);
						//sprintf(fullStr,"%s: %s: %s",firstStr,ledCol,secondStr);
						Client_PublishStringData("aodomh/feeds/led-data-feed", fullStr, 0);
						}
						if(received_data.qData == 2){
							char blueCol[5] = "Blue";
							sprintf(fullStr,"%s %s %s",firstStr,blueCol,lastStr);
							Client_PublishStringData("aodomh/feeds/led-data-feed", fullStr, 0);
							}
							if(received_data.qData == 3){
							char greenCol[7] = "Green";
							sprintf(fullStr,"%s %s %s",firstStr,greenCol,lastStr);
							Client_PublishStringData("aodomh/feeds/led-data-feed", fullStr, 0);
							}
							break;
				case OPD_ID:
					printf("Once Per Day Task Ran Successfully");
					char msg[30] = "Once Per Day Task Ran";
					Client_PublishStringData("aodomh/feeds/time-display-data-field", msg, 0);
					}
				vTaskDelay(pdMS_TO_TICKS(500));
			}




		keep_Alive();	//this will keep the connection alive if no messages are published
	}
}

/*
 * On start up this task subscribes to the LED control feed
 * It then check for a published packet from subscribed feed
 * Published packet payload is then parsed
 */
void subscribeTask(void *pvParameters) {
	publishStruct LED_data;
	char publishTopic[40], publishPayload[20];
	Client_Subscribe("aodomh/feeds/led-control-feed", 1);
	uint8_t count = 0;
	while(1) {
		if(publishPacketCheck(publishTopic, publishPayload) == SUCCESS) {

		printf("\n\rPayload %s received from topic %s\n\n\r", publishPayload, publishTopic);
		if(strstr(publishTopic, "aodomh/feeds/led-control-feed")) {	//test for message from toggle switch block
			if(strstr(publishPayload, "LED ON")) {
				count++;
				switch(count){
				case 1:
					LED_RED_ON();
					LED_data.idNumber = LED_ID;
					LED_data.qData = count;
					xQueueSend(data_Queue, &LED_data, 0);
					break;
				case 2:
					LED_BLUE_ON();
					LED_data.idNumber = LED_ID;
					LED_data.qData = count;
					xQueueSend(data_Queue, &LED_data, 0);
					break;
    			case 3:
    				LED_GREEN_ON();
    				LED_data.idNumber = LED_ID;
    				LED_data.qData = count;
    				xQueueSend(data_Queue, &LED_data, 0);
    				count = 0;
    				break;
			}
		}
		else if(strstr(publishPayload, "LED OFF")) {
			int zero = 0;
			LED_data.idNumber = LED_ID;
			LED_data.qData = zero;
			xQueueSend(data_Queue, &LED_data, 0);
			LED_BLUE_OFF();
			LED_RED_OFF();
			LED_GREEN_OFF();
		}

		}
		}
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}


//void semGive(void *pvParameters) {
//	publishStruct LED_data;
//	char publishTopic[40], publishPayload[20];
//	Client_Subscribe("aodomh/feeds/semgive", 1);
//	uint8_t count = 0;
//	while(1) {
//		if(publishPacketCheck(publishTopic, publishPayload) == SUCCESS) {
//
//		printf("\n\rPayload %s received from topic %s\n\n\r", publishPayload, publishTopic);
//		if(strstr(publishTopic, "aodomh/feeds/semgive")) {	//test for message from toggle switch block
//			if(strstr(publishPayload, "semGiv")) {
//				xSemaphoreGive(wait_Semaphore);
//			}
//		}
//		else if(strstr(publishPayload, "LED OFF")) {
//			LED_GREEN_OFF();
//		}
//
//		}
//
//		vTaskDelay(pdMS_TO_TICKS(100));
//	}
//}

/*Adding struct to manage data to publish
 *
 * added it to timedisplaytask ready to add queue
 */



void AutoReloadCallback(TimerHandle_t xTimer){
	publishStruct timeDisplay_data;

	timeSeconds++;
	if(timeSeconds == 86400){
		timeSeconds = 0;
	}

	timeDisplay_data.idNumber = TimeDisplay_ID;
	timeDisplay_data.qData = timeSeconds;
	xQueueSend(data_Queue, &timeDisplay_data, 0);



	if(GPIO_PinRead(GPIOA, 4) == 0){
		timeDisplay_data.idNumber = TimeDisplay_ID;
		timeDisplay_data.qData = timeSeconds;
		xQueueSend(data_Queue, &timeDisplay_data, 0);
		while(GPIO_PinRead(GPIOA, 4) == 0);
	}
		vTaskDelay(pdMS_TO_TICKS(3000));
}




void setTimeTask(void *pvParameters){
	publishStruct setTime_data;
	uint32_t notificationValue = 0;

	while(1){
	notificationValue = ulTaskNotifyTake(pdTRUE, 0);
		if(notificationValue != 0){
			timeSeconds = notificationValue;
			printf("%02d\n\r", notificationValue);
			setTime_data.idNumber = TimeDisplay_ID;
			setTime_data.qData = timeSeconds;
			xQueueSend(data_Queue, &setTime_data, 0);
			uint32_t notificationValue = 0;
		}
	}
}


void SW3_Display(void *pvParameters){
	publishStruct SW3_data;
	while(1){
		if(GPIO_PinRead(GPIOA, 4) == 0){
			SW3_data.qData = rand()%51;
			SW3_data.idNumber = SW3_ID;
			xQueueSend(data_Queue, &SW3_data, 0);
			while(GPIO_PinRead(GPIOA, 4) == 0);
		}
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}

void oncePerDayTask(void *pvParameters){
	publishStruct OPD_data;
	while(1){
		OPD_data.idNumber = OPD_ID;
		xQueueSend(data_Queue, &OPD_data, 0);
		vTaskDelay(pdMS_TO_TICKS(86400));
	}

}
