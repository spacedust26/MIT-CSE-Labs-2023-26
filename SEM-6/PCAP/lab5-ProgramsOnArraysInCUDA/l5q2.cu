// Lab Exercise 2 - Implement a CUDA progarm to add two vectors of length N by keeping the number of threads per block as 256(constant) and vary the number of blocks to handle N elements

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>

const int n = 1000;

__global__ void vector_addition(int *a, int *b, int *c){
    int tid = (blockIdx.x * blockDim.x) + threadIdx.x;
    if(tid < n) c[tid] = a[tid] + b[tid];
}

int main(){
    int *d_a, *d_b, *d_c; //device copies
    int size = sizeof(int);
    
    //allocate space for device copies
    cudaMalloc((void**)&d_a, n * size);
    cudaMalloc((void**)&d_b, n * size);
    cudaMalloc((void**)&d_c, n * size);

    //setup input values for host copies
    // int a[n] = {1,2,3,4,5,6,7,8,9,0};
    // int b[n] = {0,9,8,7,6,5,4,3,2,1};
    // int c[n];
    int a[n], b[n], c[n];
    for(int i = 0 ; i < n ; i++){
        a[i] = i;
        b[i] = i + 10;
    }

    //copy inputs to device
    cudaMemcpy(d_a, a, n * size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, n * size, cudaMemcpyHostToDevice);

    //launch add() kernal on GPU for N threads
    vector_addition<<<ceil((float)n/256),256>>>(d_a, d_b, d_c); //1 

    //copy results back to host
    cudaMemcpy(c, d_c, n * size, cudaMemcpyDeviceToHost);

    //printing the array
    printf("The array after vector addition using N threads is: ");
    for(int i = 0; i< n; i++){
        printf("%d ", c[i]);
    }
    printf("\n");

    //cleanup
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    return 0;
}