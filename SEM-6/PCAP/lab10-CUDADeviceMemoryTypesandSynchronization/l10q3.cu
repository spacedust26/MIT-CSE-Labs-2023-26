// Lab exercise 3 - Write a program in CUDA to perform incluisve scan algorithm

#include <stdio.h>
#include <cuda_runtime.h>

#define N 16  // Size of input array (can change as needed)

__global__ void inclusiveScanKernel(int *input, int *output, int n) {
    __shared__ int temp[N];
    int tid = threadIdx.x;

    if (tid < n)
        temp[tid] = input[tid];
    __syncthreads();

    // Inclusive scan using Hillis-Steele algorithm
    for (int offset = 1; offset < n; offset *= 2) {
        int val = 0;
        if (tid >= offset)
            val = temp[tid - offset];
        __syncthreads();
        if (tid < n)
            temp[tid] += val;
        __syncthreads();
    }

    if (tid < n)
        output[tid] = temp[tid];
}

int main() {
    int h_input[N], h_output[N];
    int *d_input, *d_output;

    // Initialize input array
    printf("Input array:\n");
    for (int i = 0; i < N; i++) {
        h_input[i] = i + 1;  // Example: 1, 2, 3, ..., N
        printf("%d ", h_input[i]);
    }
    cudaMalloc((void**)&d_input, N * sizeof(int));
    cudaMalloc((void**)&d_output, N * sizeof(int));
    cudaMemcpy(d_input, h_input, N * sizeof(int), cudaMemcpyHostToDevice);

    inclusiveScanKernel<<<1, N>>>(d_input, d_output, N);
    cudaMemcpy(h_output, d_output, N * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Inclusive scan output:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", h_output[i]);
    }
    cudaFree(d_input);
    cudaFree(d_output);
    return 0;
}
