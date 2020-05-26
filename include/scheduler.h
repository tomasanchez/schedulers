#pragma once

#include <db.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <commons/collections/queue.h>
#include <commons/process.h>
#include <semaphore.h>

/* =============================================================== Scheduler ===============================================================   */

typedef struct{

/* Scheduling algorithm */
char* algorithm;
void* picker;

} Scheduler;

Scheduler* Scheduler_create(void);
void Scheduler_destroy(Scheduler* scheduler);

/* =============================================================== Threads ===============================================================   */

void* thread_execute(void* arg);


/* =============================================================== QUEUES ===============================================================   */

typedef struct{

t_queue* new_queue;
t_queue* ready_queue;
t_queue* blocked_queue;

} Queues;

Queues* Queues_Init(void);
void  Queues_Destroy(Queues* self);

