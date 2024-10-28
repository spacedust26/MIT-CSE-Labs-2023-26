//  Write a multithreaded program that performs the sum of even numbers and odd numbers 
// in an input array. Create a separate thread to perform the sum of even numbers and odd 
// numbers. The parent thread has to wait until both the threads are done. 

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

int array[100];
void* child_thread(void * param){
    int* n = (int*)param;
    int sum = 0;
    for(int i;i<n[0];i++)
        if(array[i]%2==n[1])
            sum+=array[i];
    return (void*)(intptr_t) sum;
}
int main(){
    pthread_t thread[2];
    int n;
    void* sum[2];
    printf("Enter number of array elements : ");
    scanf("%d", &n);
    printf("Enter array elements :\n");
    for(int i=0;i<n;i++)
        scanf("%d", &array[i]);
    int odd[2] = {n, 1};
    int even[2] = {n, 0};
    pthread_create( &thread[0], 0, &child_thread, (void*)even);
    pthread_create( &thread[1], 0, &child_thread, (void*)odd);
    pthread_join(thread[0], &sum[0]);
    pthread_join(thread[1], &sum[1]);
    printf("Sum of even elements - %d\n", (int)(intptr_t)sum[0]);
    printf("Sum of odd elements - %d\n", (int)(intptr_t)sum[1]);
}