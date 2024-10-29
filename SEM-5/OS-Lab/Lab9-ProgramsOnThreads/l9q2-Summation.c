// Write a multithreaded program that calculates the summation of non-negative integers in a separate thread and passes the result to the main thread. 

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

int array[100];
void* child_thread(void * param){
    int *id = (int *)param;
    int sum = 0;
    for(int i=0;i<*id;i++){
        if(array[i]>=0)
        sum+=array[i];
    }
    return (void*)(intptr_t) sum;
}
int main(){
    pthread_t thread;
    int n;
    void* sum;
    printf("Enter number of array elements : ");
    scanf("%d", &n);
    printf("Enter array elements :\n");
    for(int i=0;i<n;i++) scanf("%d", &array[i]);
    pthread_create(&thread, 0, &child_thread, (void*)&n);
    pthread_join(thread, &sum);
    printf("Sum of elements - %d\n", (int)(intptr_t)sum);
}