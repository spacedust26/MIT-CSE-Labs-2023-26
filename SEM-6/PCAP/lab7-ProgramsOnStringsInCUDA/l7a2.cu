// Additional Exercise 2 - Write a CUDA program that takes a string Sin as input and one integer value N and produces an output string, Sout, in parallel by concatenating niput string Sin, N times as shown below.
// Input : Sin = "Hello", N = 3
// Output : Sout = "HelloHelloHello"

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>

__global__ void concatenateStrings(char *sin, char *sout, int sinLength, int n) {
    int tid = threadIdx.x;
    int index = tid * sinLength;  
    if (tid < n) {
        for (int i = 0; i < sinLength; i++) {
            sout[index + i] = sin[i];
        }
    }
}

int main() {
    char sin[100] = "Hello";   
    int n = 3;            
    char sout[100];         

    int sinLength = strlen(sin); 
    char *d_sin, *d_sout;
    cudaMalloc((void**)&d_sin, sinLength * sizeof(char));
    cudaMalloc((void**)&d_sout, sinLength * n * sizeof(char));
    cudaMemcpy(d_sin, sin, sinLength * sizeof(char), cudaMemcpyHostToDevice);

    concatenateStrings<<<1, n>>>(d_sin, d_sout, sinLength, n);
    cudaMemcpy(sout, d_sout, sinLength * n * sizeof(char), cudaMemcpyDeviceToHost);
    printf("Output string: %s\n", sout);
    cudaFree(d_sin);
    cudaFree(d_sout);
    return 0;
}
