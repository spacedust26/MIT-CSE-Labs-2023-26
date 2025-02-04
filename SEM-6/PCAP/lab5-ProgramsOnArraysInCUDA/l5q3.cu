// Lab Exercises 3 - Write a program in CUDA to process a 1D array containing angles in radian to generate sine of the angles in the output array. Use appropriate function.

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>
#define PI 3.14159265359

const int n = 6;

__global__ void angles_to_sine(double *a, double *b){
    int tid = threadIdx.x;
    if(tid < n) {
        b[tid] = sinf(a[tid]);
    }
}

int main(){
    double *d_a, *d_b; //device copies
    int size = sizeof(double);
    
    //allocate space for device copies
    cudaMalloc((void**)&d_a, n * size);
    cudaMalloc((void**)&d_b, n * size);

    //setup input values for host copies
    double a[n] = {0, PI/6, PI/4, PI/3, PI/2, PI};
    double b[n];

    //copy inputs to device
    cudaMemcpy(d_a, a, n * size, cudaMemcpyHostToDevice);

    //launch add() kernal on GPU for N threads
    angles_to_sine<<<1,n>>>(d_a, d_b);

    //copy results back to host
    cudaMemcpy(b, d_b, n * size, cudaMemcpyDeviceToHost);

    //printing the array
    printf("The 1D array containing sine of angles is: \n");
    for(int i = 0; i < n; i++){
        printf("sin(%.2lf) = %.2lf \n",a[i],b[i]);
    }
    printf("\n");

    //cleanup
    cudaFree(d_a);
    cudaFree(d_b);
    return 0;
}