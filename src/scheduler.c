#include <scheduler.h>

extern int sum;
extern pthread_mutex_t  sem;
extern fcfs_queue gqueue;

/* =============================================================== FCFS QUEUES ===============================================================   */

void fcfs_wait(fcfs_queue* queue)
{
    uint32_t turn;

    /* - -  Seccion critica - -   */
    pthread_mutex_lock(&queue->mutex);
    /* Asigno el turno y aumento total de turnos    */
    turn = queue->total_turns++;

    /* Espera activa de turno */
    while (turn != queue->current_turn)
    {
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }
    pthread_mutex_unlock(&queue->mutex);
    /* - - Fin Seccion critica - -  */
}

void fcfs_signal(fcfs_queue* queue)
{

    /* - - Seccion Critica - -  */
    pthread_mutex_lock(&queue->mutex);
    /* Paso al siguiente turno  */
    queue->current_turn++;

    pthread_cond_broadcast(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
    /* - - Fin seccion critica - - */
}

void fcfs_queue_init (fcfs_queue* queue){

    /* Ambos deben arrancar en el mismo numero, preferentemente cero */
    queue->total_turns = queue->current_turn = 0;

    /* inicializacion standard y chequeo */
    pthread_cond_init(&queue->cond, NULL);
    assert(&queue->cond);
    pthread_mutex_init(&queue->mutex,NULL);
    assert(&queue->mutex);

}

void fcfs_queue_destroy(fcfs_queue* queue){

    pthread_cond_destroy(&queue->cond);
    pthread_mutex_destroy(&queue->mutex);

}
/* =============================================================== Test ===============================================================   */

void* thread_execute(void* arg){

    int* ptr = (int*)arg;
    assert(ptr);
    int number = *ptr;

    /* FIFO  queue */
    fcfs_wait(&gqueue);
    printf("Thread: %d\tNro de Thread: %d\n", process_get_thread_id(), number);
    fcfs_signal(&gqueue);
    /* - - Fin Seccion Critica - - */

    pthread_exit(NULL);

    return NULL;
}