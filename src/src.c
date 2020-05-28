/* FCFS test
 * 
 */

#include <scheduler.h>

#define NUMBER_OF_THREADS 4

int sum = 0;
fcfs_queue gqueue;

int main(void){

    pthread_t trainer[NUMBER_OF_THREADS];
    int nrothread = 0;
   
   fcfs_queue_init(&gqueue);
   
    for(int i = 0; i < NUMBER_OF_THREADS; i++ ){
        pthread_create(&trainer[i], NULL, thread_execute, &nrothread);
        nrothread++;
    }

    for (int id = 0; id < NUMBER_OF_THREADS; id++){
        pthread_join(trainer[id], NULL);
    }

    fcfs_queue_destroy(&gqueue);

    return 0;
}