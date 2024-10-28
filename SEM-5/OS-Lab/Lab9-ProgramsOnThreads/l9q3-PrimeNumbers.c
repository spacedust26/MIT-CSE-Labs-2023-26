//  Write a multithreaded program for generating prime numbers from a given starting number 
// to the given ending number. 

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

void* child_thread(void * param){
	int n = (intptr_t)param;
	int prime = 1;
	for(int i=2;i<n;i++)
		if(n%i==0){
			prime = 0;
			break;
		}
	if(prime == 1)
		printf("%d ", n);
}
int main(){	
	int f, r, n;
	printf("Enter start point : ");
	scanf("%d", &f);
	printf("Enter end point : ");
	scanf("%d", &r);
	n = r-f+1;
	pthread_t thread[n];
	for(int i=0;i<n;i++)
		pthread_create( &thread[i], 0, &child_thread, (void*)(intptr_t)(f+i));
	for(int i=0;i<n;i++)
		pthread_join(thread[i], 0);
	printf("\n");
}