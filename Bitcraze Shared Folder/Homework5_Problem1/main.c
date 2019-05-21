#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

xTaskHandle incTaskHandle;
xTaskHandle decTaskHandle;
xTaskHandle printFinalCounterTaskHandle;

SemaphoreHandle_t incTaskDone;
SemaphoreHandle_t decTaskDone;
SemaphoreHandle_t procTask;

volatile int counter = 0;

void incCounterTask(void *pvParameters)
{
	xSemaphoreTake(procTask, ( TickType_t ) 200);
	printf("Take INC\n");
	int i;
	for(i = 0; i < 1e7; i++)
	{
	counter = counter + 1;
	}
	printf("Give INC\n");
	xSemaphoreGive(procTask); 
	xSemaphoreGive(incTaskDone); 
	vTaskDelete(incTaskHandle);
}

void decCounterTask(void *pvParameters)
{
	xSemaphoreTake(procTask, ( TickType_t ) 200);
	printf("Take DEC\n");
	int i;
	for(i = 0; i < 1e7; i++ )
	{
	counter = counter - 1;
	}
	printf("Give DEC\n");
	xSemaphoreGive(procTask);
	xSemaphoreGive(decTaskDone); 
	vTaskDelete(decTaskHandle);
}

void printFinalCounterTask(void *pvParameters)
{
    xSemaphoreTake(incTaskDone, portMAX_DELAY);
    xSemaphoreTake(decTaskDone, portMAX_DELAY);
    printf("Final value: %d\n", counter);
    vTaskDelete(printFinalCounterTaskHandle);
}

int main(int argc, char **argv)
{
	incTaskDone = xSemaphoreCreateBinary();
	decTaskDone = xSemaphoreCreateBinary();
	procTask    = xSemaphoreCreateBinary();
	xSemaphoreGive(procTask);
	xTaskCreate(incCounterTask, "Increase Counter Task", configMINIMAL_STACK_SIZE, NULL, 1, &incTaskHandle);
	xTaskCreate(decCounterTask, "Decrease Counter Task", configMINIMAL_STACK_SIZE, NULL, 1, &decTaskHandle);
	xTaskCreate(printFinalCounterTask, "Print Final Counter Task", configMINIMAL_STACK_SIZE, NULL, 1, &printFinalCounterTaskHandle);
	vTaskStartScheduler();
	for( ;; );
}
