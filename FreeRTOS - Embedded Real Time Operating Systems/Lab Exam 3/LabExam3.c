/* Aonghus O Domhnaill
 * Group B - G00293306
 * Lab Exam 3 - Countdown Timer
 * Was unable to get countdown working with software timer so used PIT interrupt instead
 */

/**
 * @file    TAD_Project_Template.c
 * @brief   Application entry point.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"


static uint32_t RTOS_RunTimeCounter; /* runtime counter, used for configGENERATE_RUNTIME_STATS */

void FTM0_IRQHandler(void) {

  /* Clear interrupt flag.*/

  FTM_ClearStatusFlags(FTM0, kFTM_TimeOverflowFlag);

  RTOS_RunTimeCounter++; /* increment runtime counter */
}

void RTOS_AppConfigureTimerForRuntimeStats(void) {

  RTOS_RunTimeCounter = 0;

  EnableIRQ(FTM0_IRQn);
}

uint32_t RTOS_AppGetRuntimeCounterValueFromISR(void) {

  return RTOS_RunTimeCounter;
}
/*
 * End of real time statistics code
 */
/* TODO: insert other definitions and declarations here. */
TimerHandle_t AutoReloadTimerHandle = NULL;
SemaphoreHandle_t PIT_Semaphore = NULL;
SemaphoreHandle_t SW2_Semaphore = NULL;
void timerTask(TimerHandle_t xTimer);
TaskHandle_t timeDisplayTaskHandle = NULL;



/*
 * @brief   Application entry point.
 */

/* PORTC_IRQn interrupt handler */
void GPIOC_IRQHANDLER(void) {
  static BaseType_t xHigherPriorityTaskWoken;
  /* Get pin flags */
  uint32_t pin_flags = GPIO_PortGetInterruptFlags(GPIOC);

  /* Place your interrupt code here */
  xHigherPriorityTaskWoken = pdFALSE;
  xSemaphoreGiveFromISR(SW2_Semaphore, &xHigherPriorityTaskWoken);
  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

  /* Clear pin flags */
  GPIO_PortClearInterruptFlags(GPIOC, pin_flags);
  //sw2_interrupt = true;
  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}



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
	  totalSeconds = atoi(temp);  //hours

	  //notify time display
	  if(totalSeconds < 60){    //check if less than seconds in day
		  xHigherPriorityTaskWoken = pdFALSE;
		  xTaskNotifyFromISR(timeDisplayTaskHandle, totalSeconds, eSetValueWithOverwrite, &xHigherPriorityTaskWoken);
		  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	  }
	  else{
		  printf("invalid timer values entered\n\r");
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



/* PIT0_IRQn interrupt handler */
void PIT_CHANNEL_0_IRQHANDLER(void) {
	static BaseType_t xHigherPriorityTaskWoken;
  uint32_t intStatus;
  /* Reading all interrupt flags of status register */
  intStatus = PIT_GetStatusFlags(PIT_PERIPHERAL, PIT_CHANNEL_0);
  PIT_ClearStatusFlags(PIT_PERIPHERAL, PIT_CHANNEL_0, intStatus);

  /* Place your code here */
  xHigherPriorityTaskWoken = pdFALSE;
  xSemaphoreGiveFromISR(PIT_Semaphore, &xHigherPriorityTaskWoken);
  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

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
                                                                //use handle to notify task
	if(xTaskCreate(timerTask, "Time Display", 100, NULL, 4, &timeDisplayTaskHandle) != pdPASS){
		printf("error creating task");
		while(1);
	}

	AutoReloadTimerHandle = xTimerCreate("Auto Reload Timer", pdMS_TO_TICKS(3000), pdTRUE, 0, timerTask);
	xTimerStart(AutoReloadTimerHandle, 0);

	PIT_Semaphore = xSemaphoreCreateBinary();
	SW2_Semaphore = xSemaphoreCreateBinary();
	vTaskStartScheduler();

    while(1) {
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}


void timerTask(TimerHandle_t xTimer){
	printf("Starting timer task\n\r");
	printf("Press SW2 for countdown 20 seconds with warning 10 seconds\n\r");
	printf("Or enter start time on serial terminal\n\r");

	uint32_t timeSeconds = 60, notificationValue = 0; //
	printf("%02d\n\r", timeSeconds);

	while(1){
		while(timeSeconds != 0){
			if(xSemaphoreTake(PIT_Semaphore,0) == pdTRUE){
				timeSeconds--;
				LED_RED_TOGGLE();
				if(timeSeconds == 0){
					printf("Timer stopped\n\r");
				}
				printf("%02d\n\r", timeSeconds);
			}
			if(xSemaphoreTake(SW2_Semaphore,0) == pdTRUE){
				printf("Starting 20 second timer with warning of 10 second\n\r");
				timeSeconds = 20;
				timeSeconds--;
				LED_RED_TOGGLE();
				if(timeSeconds == 10){
					printf("Only 10 seconds left!");
				}
				printf("%02d\n\r", timeSeconds);
				if(timeSeconds == 0){
					printf("Timer stopped\n\r");
				}
			}
			notificationValue = ulTaskNotifyTake(pdTRUE, 0);
			if(notificationValue != 0){
				timeSeconds = notificationValue;
				printf("%02d\n\r", timeSeconds);
			}

		}

	}
}
