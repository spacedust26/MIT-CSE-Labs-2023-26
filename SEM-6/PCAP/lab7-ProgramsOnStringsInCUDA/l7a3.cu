// Additional Exercise 3 - Write a CUDA program which reads a string Sin and produces an output string T as shown below.
// Input: Sin = "Hai"
// Output: T = "Haaiii"

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>

__global__ void transformString(char *sin, char *t, int sinLength) {
    int tid = threadIdx.x;
    if (tid < sinLength) {
        char ch = sin[tid];
        int startIndex = 0;
        for (int i = 0; i < tid; i++) {
            startIndex += (i + 1); 
        }
        for (int i = 0; i <= tid; i++) {
            t[startIndex + i] = ch;
        }
    }
}

int main() {
    char sin[100] = "Hai"; 
    int sinLength = strlen(sin);
    char t[100]; 
    int totalLength = (sinLength * (sinLength+1)) / 2;

    char *d_sin, *d_t;
    cudaMalloc((void**)&d_sin, sinLength * sizeof(char));
    cudaMalloc((void**)&d_t, totalLength * sizeof(char));
    cudaMemcpy(d_sin, sin, sinLength * sizeof(char), cudaMemcpyHostToDevice);

    transformString<<<1, sinLength>>>(d_sin, d_t, sinLength);
    cudaMemcpy(t, d_t, totalLength * sizeof(char), cudaMemcpyDeviceToHost);
    t[totalLength] = '\0';
    printf("Output string: %s\n", t);

    cudaFree(d_sin);
    cudaFree(d_t);
    return 0;
}
