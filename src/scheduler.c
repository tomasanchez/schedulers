#include <scheduler.h>

extern int sum;
extern pthread_mutex_t  sem;
extern fcfs_ticket tic;

/* =============================================================== FCFS QUEUES ===============================================================   */

void fcfs_wait(fcfs_ticket *ticket)
{
    uint32_t turn;
    pthread_mutex_lock(&ticket->mutex);
    /* Asigno el turno y aumento total de turnos    */
    turn = ticket->total_turns++;

    /* Espera activa de turno */
    while (turn != ticket->current_turn)
    {
        pthread_cond_wait(&ticket->cond, &ticket->mutex);
    }
    pthread_mutex_unlock(&ticket->mutex);
}

void fcfs_signal(fcfs_ticket *ticket)
{
    pthread_mutex_lock(&ticket->mutex);
    /* Paso al siguiente turno  */
    ticket->current_turn++;
    /* Aviso al mutex que se desbloquee */
    pthread_cond_broadcast(&ticket->cond);
    pthread_mutex_unlock(&ticket->mutex);
}

/* =============================================================== Execution ===============================================================   */

void* thread_execute(void* arg){
    int* ptr = (int*)arg;
    int number = *ptr;

    fcfs_wait(&tic);
    printf("Thread: %d\tId:%d\n", process_get_thread_id(), number);
    fcfs_signal(&tic);

    return NULL;
}