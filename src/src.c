/* Scheduler Testing
 *
 *  THIS IS A TEST
 *
 */

#include <scheduler.h>
#define TICKET_LOCK_INITIALIZER { PTHREAD_COND_INITIALIZER, PTHREAD_MUTEX_INITIALIZER }

int sum = 0;
pthread_mutex_t sem;
fcfs_ticket tic;

int main(void){

    pthread_t trainer[4];
    int limit = 0;

    pthread_mutexattr_t mxat;
    pthread_mutexattr_init(&mxat);
    pthread_mutexattr_init(&mxat);
   
    tic.total_turns = 0;
    tic.current_turn = 0;

    pthread_cond_init(&tic.cond, NULL);
    pthread_mutex_init(&tic.mutex, &mxat);

    //sem_init(&sem, 0, 1);

    for(int id = 0; id<4; id++ ){
        //pthread_attr_t attr;
        //pthread_attr_init(&attr);
        pthread_create(&trainer[id], NULL, thread_execute, &limit);
        limit++;
    }

    for (int id = 0; id <2; id++){
        pthread_join(trainer[id], NULL);
    }

    return 0;
}