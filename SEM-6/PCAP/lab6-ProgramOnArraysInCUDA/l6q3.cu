// Exercise 3 - Write a program in CUDA to perform odd even transposition sort in parallel

#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void oddEvenKernel(int *d_arr, int n, int phase) {
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    int i = phase % 2 == 0 ? 2 * idx : 2 * idx + 1;

    if (i + 1 < n) {
        if (d_arr[i] > d_arr[i + 1]) {
            // Swap elements
            int temp = d_arr[i];
            d_arr[i] = d_arr[i + 1];
            d_arr[i + 1] = temp;
        }
    }
}

int main() {
    const int n = 10;
    int h_arr[n] = {7,5,4,8,9,1,2,3,6,2};
    int *d_arr;
    cudaMalloc((void**)&d_arr, n * sizeof(int));
    cudaMemcpy(d_arr, h_arr, n * sizeof(int), cudaMemcpyHostToDevice);
    
    for (int phase = 0; phase < n; phase++) {
        oddEvenKernel<<<ceil((float)n/512), 512>>>(d_arr, n, phase);
        cudaDeviceSynchronize();
    }

    cudaMemcpy(h_arr, d_arr, n * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", h_arr[i]);
    cudaFree(d_arr);
    return 0;
}
