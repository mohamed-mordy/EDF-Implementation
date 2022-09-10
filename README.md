# Earliest Deadline First (EDF) Scheduler Implementation #

This repo contains my implementation of EDF Scheduler over FreeRTOS.
To use this implementation you need replace tasks.c file in FreeRTOS source code with the provided one in this repo, also task.h should be replaced.
A new Configuration parameter(configUSE_EDF_SCHEDULER) must be added to FreeRTOSConfig.h configuration header and set to 1 to actually use the EDF Scheduler.
A new function is implemented in tasks.c (xTaskCreatePeriodic), to create new tasks under EDF Scheduler.


Feel free to use my Implementation of EDF in any way you like.
