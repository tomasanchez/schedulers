#pragma once

#include <db.h>
#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/queue.h>

typedef struct{

/* Scheduling algorithm */
char* algorithm;

} Scheduler;


/*  Queues*/
typedef struct{

t_queue* new_queue;
t_queue* ready_queue;
t_queue* blocked_queue;

} Queues;

Queues* Queues_Init();
void  Queues_Destroy(Queues* self);