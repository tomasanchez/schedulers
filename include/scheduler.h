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

/*  FCFS - Turnos
    mutex atado a una condicion
    turno actual se incrementa por signal
    turnos totales se incrementa por wait
*/
typedef struct{
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    uint32_t current_turn, total_turns;
} fcfs_ticket;

/* =============================================================== Threads ===============================================================   */

/* hace un lock a los threads en una "queue" en un mutex dentro del ticket.
    incrementa el total de turnos
*/
void fcfs_wait(fcfs_ticket *ticket);

/*  libera el proximo thread en FIFO.
    pasa al siguiente turno.
*/
void fcfs_signal(fcfs_ticket *ticket);

void* thread_execute(void* arg);

