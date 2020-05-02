#include <scheduler.h>

/* =============================================================== QUEUES ===============================================================   */


Queues* Queues_Init(){

    Queues* this_queues = malloc(sizeof(Queues));

    this_queues->blocked_queue = queue_create();
    this_queues->new_queue = queue_create();
    this_queues->ready_queue = queue_create();

    return this_queues;
}

void Queues_Destroy(Queues* this_queues){

    //queue_clean_and_destroy_elements(this_queues->new_queue, *free(void));

}