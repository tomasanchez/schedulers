#include <scheduler.h>

extern int sum;
extern sem_t  sem;
/* =============================================================== QUEUES ===============================================================   */


Queues* Queues_Init(){

    Queues* this_queues = malloc(sizeof(Queues));

    this_queues->blocked_queue = queue_create();
    this_queues->new_queue = queue_create();
    this_queues->ready_queue = queue_create();

    return this_queues;
}

void Queues_Destroy(Queues* this_queues){

}

/* =============================================================== Scheduler ===============================================================   */

Scheduler* Scheduler_create(void){
    return malloc(sizeof(Scheduler));
}
void Scheduler_destroy(Scheduler* this_scheduler){
    free(this_scheduler);
}

/* =============================================================== Execution ===============================================================   */

void* thread_execute(void* arg){
    int* ptr = (int*)arg;
    int cout = *ptr;
    sem_wait(&sem);
    
    sum +=cout;

    printf("Thread: %d\nId:%d\n", process_get_thread_id(),cout);
    sem_post(&sem);
}