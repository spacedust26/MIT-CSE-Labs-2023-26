// 1. Modify the above Producer-Consumer program so that, a producer can produce at the most 10 items more than what the consumer has consumed. 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define sz 10

int arr[sz];
int produced = 0, consumed = 0;
sem_t mutex, full, empty, atmost10;

void* producer(void* param) {
    while (1) {
        while (produced - consumed >= 10) {
            usleep(100000);
        }
        
        sem_wait(&empty); 
        sem_wait(&mutex);
        
        arr[produced % sz] = produced;
        printf("Produced Item: %d (Difference: %d)\n", produced, produced - consumed);
        produced++;
        
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        
        int item = arr[consumed % sz];
        printf("Consumed Item: %d (Difference: %d)\n", item, produced - (consumed + 1));
        consumed++;
        
        sem_post(&mutex);
        sem_post(&empty);
        
        sleep(5);
    }
}

int main() {
    pthread_t th[2];
    
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, sz);
    sem_init(&atmost10, 0, 1);

    pthread_create(&th[0], NULL, producer, NULL);
    pthread_create(&th[1], NULL, consumer, NULL);
    
    pthread_join(th[0], NULL);
    pthread_join(th[1], NULL);
    
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    sem_destroy(&atmost10);
    
    return 0;
}