/* Scheduler Testing
 *
 *  THIS IS A TEST
 *
 */

#include <scheduler.h>

Scheduler* sts;
int sum = 0;
sem_t sem;

int main(void){

    pthread_t trainer[2];
    int limit = 0;
    sem_init(&sem, 0, 1);

    for(int id = 0; id<4; id++ ){
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&trainer[id],&attr, thread_execute, &limit);
        ++limit;
    }

    for (int id = 0; id <2; id++){
        pthread_join(trainer[id], NULL);
    }

    return 0;
}