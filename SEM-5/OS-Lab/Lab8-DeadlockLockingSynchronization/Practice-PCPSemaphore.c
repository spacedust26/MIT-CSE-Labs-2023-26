#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex, full, empty;
int buf[5], f, r;

void *produce(void *arg){
  for(int i = 0; i < 10; i++){
    sem_wait(&empty);
    sem_wait(&mutex);
    printf("Produced item is %d\n", i);
    buf[(++r)%5] = i;
    sleep(1);
    sem_post(&mutex);
    sem_post(&full);
    printf("Full %u\n", full);
  }
}

void *consume(void *arg){
  for(int i = 0; i < 10; i++){
    sem_wait(&full);
    printf("Full %u\n", full);
    sem_wait(&mutex);
    int item = buf[(++f)%5];
    printf("Consumed item is %d\n", item);
    sleep(1);
    sem_post(&mutex);
    sem_post(&empty);
  }
}

int main(){
  pthread_t tid1, tid2;
  sem_init(&mutex, 0, 1);
  sem_init(&full, 0, 1);
  sem_init(&empty, 0, 5);
  pthread_create(&tid1, NULL, produce, NULL);
  pthread_create(&tid2, NULL, consume, NULL);
  p_thread_join(tid1, NULL);
  p_thread_join(tid2, NULL);
  sem_destroy(&mutex);
  sem_destroy(&full);
  sem_destroy(&empty);
}