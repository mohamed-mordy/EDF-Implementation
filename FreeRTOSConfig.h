/*
 * FreeRTOS V202112.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <lpc21xx.h>
#include "GPIO.h"

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION		      1
#define configUSE_EDF_SCHEDULER           1
#define configCPU_CLOCK_HZ			      ( ( unsigned long ) 60000000 )	/* =12.0MHz xtal multiplied by 5 using the PLL. */
#define configTICK_RATE_HZ			      ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES		      ( 4 )
#define configMINIMAL_STACK_SIZE	      ( ( unsigned short ) 90 )
#define configTOTAL_HEAP_SIZE		      ( ( size_t ) 13 * 1024 )
#define configMAX_TASK_NAME_LEN		      ( 32 )
#define configUSE_TRACE_FACILITY	      1
#define configUSE_16_BIT_TICKS		      0
#define configIDLE_SHOULD_YIELD		      1
#define configUSE_TIME_SLICING            0
#define configQUEUE_REGISTRY_SIZE 	      0
#define configUSE_APPLICATION_TASK_TAG    1


/* Hook function related definitions */
#define configUSE_IDLE_HOOK		             	0
#define configUSE_TICK_HOOK		             	1
#define configCHECK_FOR_STACK_OVERFLOW          0
#define configUSE_MALLOC_FAILED_HOOK            0
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS           0
#define configUSE_STATS_FORMATTING_FUNCTIONS    0

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		      0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Set the following definitions to 1 to include the API function,
or zero to exclude the API function. */

#define INCLUDE_vTaskPrioritySet		   0
#define INCLUDE_uxTaskPriorityGet		   0
#define INCLUDE_vTaskDelete				   1
#define INCLUDE_vTaskCleanUpResources	   0
#define INCLUDE_vTaskSuspend			   1
#define INCLUDE_vTaskDelayUntil			   1
#define INCLUDE_vTaskDelay				   1
#define INCLUDE_xTaskAbortDelay            1

/* A header file that defines trace macro can be included here. */

/* Trace Hooks */

/* Called during the tick interrupt.*/
#define traceTASK_INCREMENT_TICK(xTickCount)

/*	Called before a new task is selected to run. At this point pxCurrentTCB 
 *	contains the handle of the task about to leave the Running state.*/
#define traceTASK_SWITCHED_OUT()

/* Called after a task has been selected to run. At this point pxCurrentTCB 
 * contains the handle of the task about to enter the Running state.*/
#define traceTASK_SWITCHED_IN()

/*	Called when a task is transitioned into the Ready state.*/
#define traceMOVED_TASK_TO_READY_STATE(xTask)

/*	Indicates that the currently executing task is about to block following an attempt to 
 *	read from an empty queue, or an attempt to 'take' an empty semaphore or mutex.*/
#define traceBLOCKING_ON_QUEUE_RECEIVE(xQueue)

/*	Indicates that the currently executing task is about to block following an attempt to write to a full queue.*/
#define traceBLOCKING_ON_QUEUE_SEND(xQueue)

/*	Called from within xSemaphoreGiveRecursive().*/
#define traceGIVE_MUTEX_RECURSIVE(xMutex)

/*	Called from within xSemaphoreGiveRecursive().*/
#define traceGIVE_MUTEX_RECURSIVE_FAILED(xMutex)

/*	Called from within xQueueCreate() or xQueueCreateStatic() if the queue was successfully created.*/
#define traceQUEUE_CREATE(pxNewQueue)

/*	Called from within xQueueCreate() or xQueueCreateStatic() if the queue was not successfully 
 *	created due to there being insufficient heap memory available.*/
#define traceQUEUE_CREATE_FAILED( ucQueueType )

/*	Called from within xSemaphoreCreateMutex() if the mutex was successfully created.*/
#define traceCREATE_MUTEX(pxNewMutex)

/*	Called from within xSemaphoreCreateMutex() if the mutex was not successfully 
 *	created due to there being insufficient heap memory available.*/
#define traceCREATE_MUTEX_FAILED()

/*	Called from within xSemaphoreGiveRecursive() if the mutex was successfully 'given'.*/
#define traceGIVE_MUTEX_RECURSIVE(xMutex)

/*	Called from within xSemaphoreGiveRecursive() if the mutex was not 
 *	successfully given as the calling task was not the mutex owner.*/
#define traceGIVE_MUTEX_RECURSIVE_FAILED(xMutex)

/*	Called from within xQueueTakeMutexRecursive().*/
#define traceTAKE_MUTEX_RECURSIVE(xMutex)

/*	Called from within xSemaphoreCreateCounting() if the semaphore was successfully created.*/
#define traceCREATE_COUNTING_SEMAPHORE()

/*	Called from within xSemaphoreCreateCounting() if the semaphore was not 
 *	successfully created due to insufficient heap memory being available.*/
#define traceCREATE_COUNTING_SEMAPHORE_FAILED()

/*	Called from within xQueueSend(), xQueueSendToFront(), xQueueSendToBack(), or any 
 *	of the semaphore 'give' functions, when the queue send was successful.*/
#define traceQUEUE_SEND(xQueue)

/*	Called from within xQueueSend(), xQueueSendToFront(), xQueueSendToBack(), or any of the semaphore 'give' functions 
 *	when the queue send operation failed due to the queue being full (after any block time that was specified).*/
#define traceQUEUE_SEND_FAILED(xQueue)

/*	Called from within xQueueReceive() or any of the semaphore 'take' functions when the queue receive was successful.*/
#define traceQUEUE_RECEIVE(xQueue)

/*	Called from within xQueueReceive() or any of the semaphore 'take' functions when the queue receive 
 *	operation failed because the queue was empty (after any block time that was specified).*/
#define traceQUEUE_RECEIVE_FAILED(xQueue)

/*	Called from within xQueuePeek()*/
#define traceQUEUE_PEEK(xQueue)

/*	Called from within xQueueSendFromISR() when the send operation was successful.*/
#define traceQUEUE_SEND_FROM_ISR(xQueue)

/*	Called from within xQueueSendFromISR() when the send operation failed due to the queue already being full.*/
#define traceQUEUE_SEND_FROM_ISR_FAILED(xQueue)

/*	Called from within xQueueReceiveFromISR() when the receive operation was successful.*/
#define traceQUEUE_RECEIVE_FROM_ISR(xQueue)

/*	Called from within xQueueReceiveFromISR() when the receive operation failed due to the queue already being empty.*/
#define traceQUEUE_RECEIVE_FROM_ISR_FAILED(xQueue)

/*	Called from within vQueueDelete().*/
#define traceQUEUE_DELETE(xQueue)

/*	Called from within xTaskCreate() (or xTaskCreateStatic()) when the task is successfully created.*/
#define traceTASK_CREATE(xTask)

/*	Called from within xTaskCreate() (or xTaskCreateStatic()) when the task was not 
 *	successfully created due to there being insufficient heap space available.*/
#define traceTASK_CREATE_FAILED(pxNewTCB)

/*	Called from within vTaskDelete().*/
#define traceTASK_DELETE(xTask)

/*	Called from within vTaskDelayUntil().*/
#define traceTASK_DELAY_UNTIL( xTimeToWake )

/*	Called from within vTaskDelay().*/
#define traceTASK_DELAY()

/*	Called from within vTaskPrioritySet().*/
#define traceTASK_PRIORITY_SET(xTask,uxNewPriority)

/*	Called from within vTaskSuspend().*/
#define traceTASK_SUSPEND(xTask)

/*	Called from within vTaskResume().*/
#define traceTASK_RESUME(xTask)

/*	Called from within xTaskResumeFromISR().*/
#define traceTASK_RESUME_FROM_ISR(xTask)

/*	Called within the timer service task each time it receives 
 *	a command, before the command is actually processed.*/
#define traceTIMER_COMMAND_RECEIVED(pxTimer, xCommandID, xCommandValue)

/*	Called from within any API function that sends a command to the timer service task, for example, xTimerReset(), 
 *	xTimerStop(), etc. xStatus will be pdFAIL if the command was not successfully sent to the timer command queue.*/
#define traceTIMER_COMMAND_SEND(pxTimer, xCommandID, xOptionalValue, xStatus)

/*	Called from within xTimerCreate() if the timer was successfully created.*/
#define traceTIMER_CREATE(pxNewTimer)

/*	Called from within xTimerCreate() if the timer was not successfully 
 *	created due to there being insufficient heap memory available.*/
#define traceTIMER_CREATE_FAILED()

/*	Called when a software timer expires, before the timer callback is executed.*/
#define traceTIMER_EXPIRED(pxTimer)



#endif /* FREERTOS_CONFIG_H */

