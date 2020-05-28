#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <inttypes.h>
#include <assert.h>
#include <commons/process.h>

/* =============================================================== FCFS Queue ===============================================================   */

/*  FCFS - Turnos
    mutex atado a una condicion
    turno actual se incrementa por signal
    turnos totales se incrementa por wait
*/
typedef struct fcfs_queue{
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    uint32_t current_turn, total_turns;
} fcfs_queue;

/* hace un lock a los threads en una "queue" en un mutex.
    incrementa el total de turnos
*/
void fcfs_wait(fcfs_queue* queue);

/*  libera el proximo thread en FIFO.
    pasa al siguiente turno.
*/
void fcfs_signal(fcfs_queue* queue);

/* inicializa FIFO queue  */
void fcfs_queue_init(fcfs_queue* queue);

/* libera los recursos  */
void fcfs_queue_destroy(fcfs_queue* queue);

/* =============================================================== Threads ===============================================================   */



/* test function */
void* thread_execute(void* arg);

