// Lab Exercises 1 - Write a program in CUDA to add two vectors of length N using a) block size as N b) N threads

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>

const int n = 10;

__global__ void vector_additionNblocks(int *a, int *b, int *c){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if(tid < n) c[tid] = a[tid] + b[tid];
}

__global__ void vector_additionNthreads(int *a, int *b, int *c){
    int tid = threadIdx.x;
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
    int a[n] = {1,2,3,4,5,6,7,8,9,0};
    int b[n] = {0,9,8,7,6,5,4,3,2,1};
    int c[n];

    //copy inputs to device
    cudaMemcpy(d_a, a, n * size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, n * size, cudaMemcpyHostToDevice);

    //launch add() kernal on GPU for block size as N
    vector_additionNblocks<<<n,1>>>(d_a, d_b, d_c);

    //copy results back to host
    cudaMemcpy(c, d_c, n * size, cudaMemcpyDeviceToHost);

    //printing the array
    printf("The array after vector addition using N blocks is: ");
    for(int i = 0; i< n; i++){
        printf("%d ", c[i]);
    }
    printf("\n");

    //launch add() kernal on GPU for N threads
    vector_additionNthreads<<<1,n>>>(d_a, d_b, d_c); 

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