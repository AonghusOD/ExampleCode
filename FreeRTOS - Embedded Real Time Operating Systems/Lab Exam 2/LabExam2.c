/* Aonghus O Domhnaill
 * G00293306
 * Lab Exam 2 - Embedded Systems
*/

/**
 * @file    LabExam2.c
 * @brief   Application entry point.
 */
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "semphr.h"


#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
static void StopwatchTask(void *pvParameters);
SemaphoreHandle_t OneSecondSemaphore = NULL, PIT_Semaphore = NULL;
EventGroupHandle_t UART_EventGroup = NULL;
SemaphoreHandle_t SW3_Semaphore = NULL;

#define goBit (1<<0)
#define lapBit (1<<1)
#define stopBit (1<<2)


/* PORTA_IRQn interrupt handler */
void GPIOA_IRQHANDLER(void) {
	static BaseType_t xHigherPriorityTaskWoken;
  /* Get pin flags */
  uint32_t pin_flags = GPIO_PortGetInterruptFlags(GPIOA);

  /* Place your interrupt code here */
  xHigherPriorityTaskWoken = pdFALSE;
  xSemaphoreGiveFromISR(SW3_Semaphore, &xHigherPriorityTaskWoken );
  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

  /* Clear pin flags */
  GPIO_PortClearInterruptFlags(GPIOA, pin_flags);

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
  xSemaphoreGiveFromISR(PIT_Semaphore, &xHigherPriorityTaskWoken );
  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

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
  uint8_t ch;
  /* Reading all interrupt flags of status registers */
  intStatus = UART_GetStatusFlags(UART0_PERIPHERAL);


  /* Place your code here */
  ch = UART_ReadByte(UART0);
    xHigherPriorityTaskWoken = pdFALSE;
    switch(ch) {
    case 'g': xEventGroupSetBitsFromISR(UART_EventGroup, goBit, &xHigherPriorityTaskWoken); break;
    case 'l': xEventGroupSetBitsFromISR(UART_EventGroup, lapBit, &xHigherPriorityTaskWoken); break;
    case 's': xEventGroupSetBitsFromISR(UART_EventGroup, stopBit, &xHigherPriorityTaskWoken); break;
    default: printf("Invalid char\n\r");
    }
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

    if(xTaskCreate(StopwatchTask, "Stopwatch Task", 100, NULL, 3, NULL) != pdPASS){
          printf("StopwatchTask Create Failed\n\r");
          while(1);
    }
    PIT_Semaphore = xSemaphoreCreateBinary();
    UART_EventGroup = xEventGroupCreate();

    SW3_Semaphore = xSemaphoreCreateBinary();

    vTaskStartScheduler();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}


static void StopwatchTask(void *pvParameters){
		printf("Starting Stop watch Task\n\r");
		uint32_t time = 0;
		uint32_t lap = 0;
		uint32_t total = 0;
		uint32_t fastestLap = 0;
		uint32_t averageLap = 0;
		EventBits_t UART_Bits;

		while(1){
			if(xSemaphoreTake(PIT_Semaphore, 0) == pdTRUE){
				time++;
			}

			UART_Bits = xEventGroupWaitBits(UART_EventGroup, goBit | lapBit | stopBit,  pdTRUE, pdFALSE, 0);
			if(UART_Bits & goBit){
				PIT_StartTimer(PIT,0);
				printf("Stop watch Started. Press l for Lap time, Press s to stop\n\r");
			}
			else if(UART_Bits & lapBit){
				lap++;
				time = 0;
				total = total + time;
				printf("Lap:%d Lap time: %.2d seconds Total Time: %.2d\n\r", lap, time, total);
			}
			else if(UART_Bits & stopBit){
				PIT_StopTimer(PIT,0);
				if(fastestLap < time)
					fastestLap = time;
				lap++;
				averageLap = (fastestLap + averageLap) / lap;
				time = 0;
				lap = 0;
				printf("Stopping Stopwatch\n\r");
				printf("Total Time: %2d seconds\tFastest Lap: %.2d\tAverage Lap: %.2d\n\r", time, fastestLap, averageLap);
				printf("Press g to start stopwatch\n\r");
			}
//			if(xSemaphoreTake(SW3_Semaphore, portMAX_DELAY) == pdTRUE){
//				//time = 0;
//				lap++;
//				printf("Time is: %d\n\r", time);
//			}
		}




}
