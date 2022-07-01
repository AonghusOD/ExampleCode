/*Aonghus O Donnell
 * G00293306
 * LabExam1.c Part B
 */
#include "freeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "fsl_uart.h"



#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

SemaphoreHandle_t SW2_Semaphore = NULL;
SemaphoreHandle_t SW3_Semaphore = NULL;
SemaphoreHandle_t UART_Semaphore = NULL;

static void count_task(void *pvParameters);
static void SW3_task(void *pvParameters);
static void SW2_task(void *pvParameters);
static void UART_task(void *pvParameters);
uint8_t count = 10;

/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    printf("Counter Menu\n\ru\tCount up\n\rd\tCount Down\n\r");
    printf("Press SW2 to reset count to 0");
    printf("Press SW2 to reset count to 10");
    if(xTaskCreate(count_task, "Count Task", 100, NULL, 4, NULL) != pdPASS){
            	printf("Count Task Create Failed\n\r");
            	while(1);
    }
    if(xTaskCreate(SW2_task, "SW2 Task", 100, NULL, 3, NULL) != pdPASS){
                printf("SW2 Task Create Failed\n\r");
                while(1);
    }
    if(xTaskCreate(SW3_task, "SW2 Task", 100, NULL, 3, NULL) != pdPASS){
            	printf("SW3 Task Create Failed\n\r");
            	while(1);
    }
    if(xTaskCreate(UART_task, "UART Task", 100, NULL, 3, NULL) != pdPASS){
                printf("UART Task Create Failed\n\r");
                while(1);
    }


    SW2_Semaphore = xSemaphoreCreateBinary();
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



static void UART_task(void *pvParameters)
{
	uint8_t ch, buffer[3];
	memset(buffer, 0, sizeof(buffer));
	printf("Starting UART Task\n\r");
	while(1)
	{
		if(UART_GetStatusFlags(UART0) & kUART_RxDataRegFullFlag)
		{
			ch = UART_ReadByte(UART0);
			if(ch == 't')
			{
				printf("Enter new start time\n\r");
				UART_ReadBlocking(UART0, buffer, 1);
				count = atoi((char *)buffer);
				memset(buffer, 0, sizeof(buffer));
				if(count == 'u')
				{
					xSemaphoreGive(UART_Semaphore);
				}
				else
				{
					printf("Invalid input\n\r");
				}
			}
			else
			{
				printf("Invalid Entry, Try again\n\r");
			}
		}
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}


void count_task(void *pvParameters){
	printf("Starting Timer Task\n\r");
	while(1){
		printf("%d\n\r", count);
		if(count > 0){
			vTaskDelay(pdMS_TO_TICKS(1000));
			count--;
		}
//			printf("%d\n\r", count);
//			if(count >= 0){
//				vTaskDelay(pdMS_TO_TICKS(1000));
//				count++;
//			}
//			if(count == 10)
//				count--;
			if(xSemaphoreTake(SW2_Semaphore, 0) == pdTRUE){
				count = 0;
			}
			if(xSemaphoreTake(SW3_Semaphore, 0) == pdTRUE){
				count = 10;
			}
			if(xSemaphoreTake(UART_Semaphore, 0) == pdTRUE){
				count = 10;
				printf("New Countdown Time Entered: %d \n\r", count);
			}

}
}

//
void SW2_task(void *pvParameters){
	printf("Starting SW2 Task\n\r");
		while(1){
			//printf("Too far in SW2 Task\n\r");
			if(GPIO_PinRead(GPIOC, 6) == 0){//wait for switch press
				while(GPIO_PinRead(GPIOC, 6) == 0);//wait for switch release
				xSemaphoreGive(SW2_Semaphore);
			}
		}
	vTaskDelay(pdMS_TO_TICKS(100));
}


void SW3_task(void *pvParameters){
	printf("Starting SW3 Task\n\r");
		while(1){
			if(GPIO_PinRead(GPIOA, 4) == 0){//wait for switch press
				while(GPIO_PinRead(GPIOA, 4) == 0);//wait for switch release
				xSemaphoreGive(SW2_Semaphore);
			}
		}
	vTaskDelay(pdMS_TO_TICKS(100));
}
