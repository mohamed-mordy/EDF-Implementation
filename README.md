# Earliest Deadline First (EDF) Implementation #

This repo contains my implementation of EDF over FreeRTOS.
To use this implementation you need replace tasks.c file in FreeRTOS source code with the in this repo, also with task.h.
A new Configuration parameter(configUSE_EDF_SCHEDULER) must be added to FreeRTOSConfig.h configuration header and set to 1.
A new function is implemented in tasks.c (xTaskCreatePeriodic), to create new tasks under EDF Scheduler.


Feel free to use my Implementation of EDF in any way you like.
