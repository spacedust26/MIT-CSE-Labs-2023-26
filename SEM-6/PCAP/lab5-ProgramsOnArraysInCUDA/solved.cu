// Solved Exercise - Program to add 2 numbers
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void add(int *d_a, int *d_b, int *d_c){
    *d_c = *d_a + *d_b;
}

int main(){
    int h_a = 5, h_b = 3, h_c;
    int *d_a, *d_b, *d_c;
    int size = sizeof(int);

    // Allocate memory and copy contents
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);
    cudaMemcpy(d_a, &h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &h_b, size, cudaMemcpyHostToDevice);
    
    // Launch kernerl
    add<<<1,1>>>(d_a, d_b, d_c);

    // Result display
    cudaMemcpy(&h_c, d_c, size, cudaMemcpyDeviceToHost);
    printf("Addition result : %d", h_c);

    // Cleanup 
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    return 0;
}
