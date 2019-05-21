#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#define MIN_CROSSING_DELAY 500
#define CROSSING_DELAY 1000
#define ARRIVE_DELAY 1500

xTaskHandle *batTaskHandles; // Create as a pointer since the number of bats are unknown at compile time

int *batIds;

volatile int counter = 0;

SemaphoreHandle_t semCrossing;

SemaphoreHandle_t cNorth;
SemaphoreHandle_t cSouth;
SemaphoreHandle_t cEast;
SemaphoreHandle_t cWest;


void printBalance()
{
    vPrintf("      | %d |      \n",(int)uxSemaphoreGetCount(cNorth));
    vPrintf("   ---     ---    \n");
    vPrintf("    %d       %d   \n",(int)uxSemaphoreGetCount(cWest),(int)uxSemaphoreGetCount(cEast));
    vPrintf("   ---     ---    \n");
    vPrintf("      | %d |      \n",(int)uxSemaphoreGetCount(cSouth));
}

int deadLock()
{
    return( uxSemaphoreGetCount(cNorth)>0 && uxSemaphoreGetCount(cSouth)>0 && uxSemaphoreGetCount(cEast)>0 && uxSemaphoreGetCount(cWest)>0 );
}

void goSouth(int batId)
{
    const TickType_t waitingToArriveDelay = (rand() % ARRIVE_DELAY) / portTICK_PERIOD_MS; // Generate a random delay 
    const TickType_t crossingDelay = (rand() % CROSSING_DELAY + MIN_CROSSING_DELAY) / portTICK_PERIOD_MS; 
    
    vPrintf("BAT %d from North has started to run and is on its way to the crossing\n", batId);

    vTaskDelay(waitingToArriveDelay);   

    xSemaphoreGive(cNorth);
    vPrintf("BAT %d from North arrives at crossing\n", batId);
    printBalance();
    
    while( (uxSemaphoreGetCount(cWest) || uxSemaphoreGetCount(semCrossing) == 0) && deadLock()==0 )
    {
        //vPrintf("%d - %d\n",uxSemaphoreGetCount(cWest), uxSemaphoreGetCount(semCrossing) );
    }

    xSemaphoreTake(semCrossing, portMAX_DELAY);
    vPrintf("BAT %d from North enters crossing\n", batId);

    vTaskDelay(crossingDelay);   

    vPrintf("BAT %d from North leaving crossing\n", batId);    
    xSemaphoreGive(semCrossing);
    xSemaphoreTake(cNorth , portMAX_DELAY);
    printBalance();	

    vTaskDelay(waitingToArriveDelay);
}

void goNorth(int batId)
{
    const TickType_t waitingToArriveDelay = (rand() % ARRIVE_DELAY) / portTICK_PERIOD_MS; // Generate a random delay 
    const TickType_t crossingDelay = (rand() % CROSSING_DELAY + MIN_CROSSING_DELAY) / portTICK_PERIOD_MS;
 
    vPrintf("BAT %d from South has started to run and is on its way to the crossing\n", batId);

    vTaskDelay(waitingToArriveDelay);   
  
    xSemaphoreGive(cSouth);
    vPrintf("BAT %d from South arrives at crossing\n", batId);
    printBalance();

    while( uxSemaphoreGetCount(cEast) || uxSemaphoreGetCount(semCrossing) == 0 )
    {}

    xSemaphoreTake(semCrossing, portMAX_DELAY);
    vPrintf("BAT %d from South enters crossing\n", batId);

    vTaskDelay(crossingDelay);   

    vPrintf("BAT %d from South leaving crossing\n", batId);
    xSemaphoreGive(semCrossing);   
    xSemaphoreTake(cSouth , portMAX_DELAY);
    printBalance();

    vTaskDelay(waitingToArriveDelay);
}

void goEast(int batId)
{
    const TickType_t waitingToArriveDelay = (rand() % ARRIVE_DELAY) / portTICK_PERIOD_MS; // Generate a random delay   
    const TickType_t crossingDelay = (rand() % CROSSING_DELAY + MIN_CROSSING_DELAY) / portTICK_PERIOD_MS; 
    
    vPrintf("BAT %d from West has started to run and is on its way to the crossing\n", batId);

    vTaskDelay(waitingToArriveDelay);   

    xSemaphoreGive(cWest);
    vPrintf("BAT %d from West arrives at crossing\n", batId);
    printBalance();
    
    while( uxSemaphoreGetCount(cSouth) || uxSemaphoreGetCount(semCrossing)==0 )
    {}

    xSemaphoreTake(semCrossing, portMAX_DELAY);
    vPrintf("BAT %d from West enters crossing\n", batId);

    vTaskDelay(crossingDelay);   

    vPrintf("BAT %d from West leaving crossing\n", batId);    
    xSemaphoreGive(semCrossing);
    xSemaphoreTake(cWest , portMAX_DELAY);
    printBalance();

    vTaskDelay(waitingToArriveDelay);
}

void goWest(int batId)
{
    const TickType_t waitingToArriveDelay = (rand() % ARRIVE_DELAY) / portTICK_PERIOD_MS; // Generate a random delay 
    const TickType_t crossingDelay = (rand() % CROSSING_DELAY + MIN_CROSSING_DELAY) / portTICK_PERIOD_MS; 
     
    vPrintf("BAT %d from East has started to run and is on its way to the crossing\n", batId);

    vTaskDelay(waitingToArriveDelay);   

    xSemaphoreGive(cEast);
    vPrintf("BAT %d from East arrives at crossing\n", batId);
    printBalance();
    
    while( uxSemaphoreGetCount(cNorth) || uxSemaphoreGetCount(semCrossing)==0 )
    {
    }

    xSemaphoreTake(semCrossing, portMAX_DELAY);
    vPrintf("BAT %d from East enters crossing\n", batId);

    vTaskDelay(crossingDelay);   

    vPrintf("BAT %d from East leaving crossing\n", batId);    
    xSemaphoreGive(semCrossing);
    xSemaphoreTake(cEast , portMAX_DELAY);
    printBalance();

    vTaskDelay(waitingToArriveDelay);
}

void batFromNorth(void *pvParameters)
{
    int batId = *(int *)pvParameters;
    
    while (1) // Repeat forever
    {

        goSouth(batId); 
        goNorth(batId);
    }
}

void batFromSouth(void *pvParameters)
{
    int batId = *(int *)pvParameters;
    
    while (1)
    {
        goNorth(batId); 
        goSouth(batId);
    }
}

void batFromEast(void *pvParameters)
{
    int batId = *(int *)pvParameters;
    
    while (1)
    {
        goWest(batId); 
        goEast(batId);
    }
}

void batFromWest(void *pvParameters)
{
    int batId = *(int *)pvParameters;
    
    while (1)
    {
        goEast(batId); 
        goWest(batId);
    }
}


int main(int argc, char **argv)
{
    int batId;
    int numberOfBats;

	//vPrintf("Testing");
        
    if (argc < 2)
    {
    	vPrintf("Argument missing, specify sequence of arrivals. Example: ./batman nsewwewn\n");
    	exit(-1);
    }
    
    char *commands = argv[1];
    numberOfBats = strlen(argv[1]);

    batTaskHandles = malloc(sizeof(xTaskHandle) * numberOfBats); // Allocate memory for the task handles
    batIds = malloc(sizeof(int) * numberOfBats); // Allocate memory for the task ids

    semCrossing = xSemaphoreCreateMutex();
    xSemaphoreGive(semCrossing);

    cNorth = xSemaphoreCreateCounting( 100, 0 );
    cSouth = xSemaphoreCreateCounting( 100, 0 );
    cEast  = xSemaphoreCreateCounting( 100, 0 );
    cWest  = xSemaphoreCreateCounting( 100, 0 );
       
    for (batId = 0; batId < numberOfBats; batId++)
    {
    	batIds[batId] = batId;
    	char currentBatDirection = (argv[1])[batId];
    	char batTaskIdentity[50];
    	
    	if (currentBatDirection == 'n')
    	{
    	    sprintf(batTaskIdentity, "Bat %d from North", batId);
      	    xTaskCreate(batFromNorth, batTaskIdentity, configMINIMAL_STACK_SIZE, (void *)&batIds[batId], 1, batTaskHandles[batId]);  
      	    vPrintf("Created task \"Bat %d from North\"\n", batId); 	
    	}
    	else if (currentBatDirection == 's')
    	{
      	    sprintf(batTaskIdentity, "Bat %d from South", batId);
      	    xTaskCreate(batFromSouth, batTaskIdentity, configMINIMAL_STACK_SIZE, (void *)&batIds[batId], 1, batTaskHandles[batId]);  
      	    vPrintf("Created task \"Bat %d from South\"\n", batId);   	
    	}
     	else if (currentBatDirection == 'e')
    	{
     	    sprintf(batTaskIdentity, "Bat %d from East", batId);
      	    xTaskCreate(batFromEast, batTaskIdentity, configMINIMAL_STACK_SIZE, (void *)&batIds[batId], 1, batTaskHandles[batId]);  
      	    vPrintf("Created task \"Bat %d from East\"\n", batId);    	
    	}  
    	else if (currentBatDirection == 'w')
    	{
     	    sprintf(batTaskIdentity, "Bat %d from West", batId);
      	    xTaskCreate(batFromWest, batTaskIdentity, configMINIMAL_STACK_SIZE, (void *)&batIds[batId], 1, batTaskHandles[batId]);  
      	    vPrintf("Created task \"Bat %d from West\"\n", batId);    	
    	}    	
    	else
    	{
     	    vPrintf("Unknown direction: %c\n", currentBatDirection);
    	    exit(-1);   	
    	} 	

    }
    
    vTaskStartScheduler();
    while (1)
    {
    	// Do nothing
    };
 
    free(batTaskHandles); // Return memory for the task handles
    return 0;
}

