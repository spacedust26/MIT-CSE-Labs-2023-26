// Write a C program for the first readers-writers problem using semaphores.
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt;
pthread_mutex_t mutsem;
int count = 1;
int numreader = 0;

void *writer(void *wno) {
	sem_wait(&wrt);
	count *= 2;
	printf("Writer %d modified 'count' to %d\n", (*((int *)wno)), count);
	sem_post(&wrt);
}

void *reader(void *rno) {
	pthread_mutex_lock(&mutsem);
	numreader++;

	if (numreader == 1)
		sem_wait(&wrt);
	pthread_mutex_unlock(&mutsem);

	printf("Reader %d: read 'count' as %d\n", *((int *)rno), count);

	pthread_mutex_lock(&mutsem);
	numreader--;

	if (numreader == 0)
		sem_post(&wrt);
	pthread_mutex_unlock(&mutsem);
}

int main() {
	pthread_t read[10], write[5];
	pthread_mutex_init(&mutsem, NULL);
	sem_init(&wrt, 0, 1);
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	for (int i = 0; i < 10; i++)
		pthread_create(&read[i], NULL, reader, &a[i]);
	for (int i = 0; i < 5; i++)
		pthread_create(&write[i], NULL, writer, &a[i]);
	for (int i = 0; i < 10; i++)
		pthread_join(read[i], NULL);
	for (int i = 0; i < 5; i++)
		pthread_join(write[i], NULL);

	pthread_mutex_destroy(&mutsem);
	sem_destroy(&wrt);
	return 0;
}