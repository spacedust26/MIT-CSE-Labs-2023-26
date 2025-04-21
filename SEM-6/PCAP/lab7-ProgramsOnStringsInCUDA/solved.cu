// Solved Exercise - A CUDA program which takes a string as input and determines the number of occurances of a character 'a' in the string. This program uses atomicAdd() function.

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 256

__global__ void CUDACount(char *A, unsigned int *d_count){
    int i = threadIdx.x;
    if(A[i] == 'a') atomicAdd(d_count, 1);
}

int main(){
    char A[N];
    char *d_A;
    unsigned int *count = 0, *d_count, *result;

    printf("Enter a string: ");
    scanf("%s", A);

    result = (unsigned int*)malloc(sizeof(unsigned int)); 

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start, 0);

    cudaMalloc((void**)&d_A, N * sizeof(char)); 
    cudaMalloc((void**)&d_count, sizeof(unsigned int));

    cudaMemcpy(d_count, count, sizeof(unsigned int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_A, A, strlen(A) * sizeof(char), cudaMemcpyHostToDevice);

    cudaError_t error = cudaGetLastError();
    if(error != cudaSuccess) printf("CUDA Error1: %s\n", cudaGetErrorString(error));

    CUDACount<<<1, strlen(A)>>>(d_A, d_count);

    error = cudaGetLastError();
    if(error != cudaSuccess) printf("CUDA Error2: %s\n", cudaGetErrorString(error));

    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, start, stop);

    cudaMemcpy(result, d_count, sizeof(unsigned int), cudaMemcpyDeviceToHost);

    printf("Total occurrences of 'a' = %u\n", *result);
    printf("Time taken = %f ms\n", elapsedTime);

    cudaFree(d_A);
    cudaFree(d_count);
    free(result);  
    return 0;
}
