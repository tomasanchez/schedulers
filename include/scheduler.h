#pragma once

#include <db.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <commons/collections/queue.h>
#include <commons/process.h>
#include <semaphore.h>

/* =============================================================== FCFS Queue ===============================================================   */

/*  Turnos por FIFO */
typedef struct{
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    uint32_t queue_head, queue_tail;
} fcfs_ticket;

/* =============================================================== Threads ===============================================================   */

/* hace un lock a los threads en una "queue" en un mutex dentro del ticket    */
void fcfs_wait(fcfs_ticket *ticket);

/*  libera el proximo thread en FIFO    */
void fcfs_signal(fcfs_ticket *ticket);

void* thread_execute(void* arg);

