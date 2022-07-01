/*Aonghus O Donnell
 * G00293306
 * LabExam1.c Part A
 */
#include "freeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
static void startup_task(void *Parameters);
static void task2(void *Parameters);


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

    xTaskCreate(startup_task, "Startup Task", 200, NULL, 3, NULL);

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



void startup_task(void *parameters){
	printf("Starting Startup Task\n\n\r");
	printf("Waiting for SW2 press\n\r");
	while(1){
		if(GPIO_PinRead(GPIOC, 6) == 0){//wait for switch press
			printf("SW2 press detected, Creating Task 2\n\n\r");
			xTaskCreate(task2, "Switch2 Task", 200, NULL, 3, NULL);}
		//while(GPIO_PinRead(GPIOC, 6) == 0);//wait for switch release
//			xSemaphoreGive(SW2_Semaphore);
		//}
		vTaskDelay(pdMS_TO_TICKS(100));
	}


}

void task2(void *parameters){
	printf("Starting Task2\n\r");
	printf("Waiting for SW3 press");
	while(1){
		//printf("Waiting for SW3 press");
		if(GPIO_PinRead(GPIOA, 4) == 0){//wait for switch press
		printf("SW3 detected,Deleting Task 2\n\n\r");
		printf("Waiting for SW2 press\n\r");
		vTaskDelete(NULL);
		}
		//while(GPIO_PinRead(GPIOA, 4) == 0);
		vTaskDelay(pdMS_TO_TICKS(100));
	}


}
