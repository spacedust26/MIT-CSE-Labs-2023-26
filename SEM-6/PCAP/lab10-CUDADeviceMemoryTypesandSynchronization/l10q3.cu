#include <stdio.h>
#include <cuda.h>
#define BLOCK_SIZE 256 

__global__ void inclusiveScanKernel(int *d_out, int *d_in, int n) {
    __shared__ int temp[BLOCK_SIZE];  // Shared memory for block scan
    int thid = threadIdx.x;
    // Load input into shared memory
    int ai = thid;
    if (ai < n) temp[ai] = d_in[ai];
    else temp[ai] = 0;
    __syncthreads();
    // Up-sweep (reduction phase)
    for (int d = 1; d < BLOCK_SIZE; d *= 2) {
        if (thid >= d)  temp[thid] += temp[thid - d];
        __syncthreads();
    }
    // Write results to global memory
    if (thid < n) d_out[thid] = temp[thid];
}

void inclusiveScan(int *h_out, int *h_in, int n) {
    int *d_in, *d_out;
    size_t size = n * sizeof(int);
    cudaMalloc((void**)&d_in, size);
    cudaMalloc((void**)&d_out, size);
    cudaMemcpy(d_in, h_in, size, cudaMemcpyHostToDevice);
    int blocks = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
    inclusiveScanKernel<<<blocks, BLOCK_SIZE>>>(d_out, d_in, n);
    cudaMemcpy(h_out, d_out, size, cudaMemcpyDeviceToHost);
    cudaFree(d_in);
    cudaFree(d_out);
}

int main() {
    int n = 10;
    int h_in[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int h_out[10];
    inclusiveScan(h_out, h_in, n);
    printf("Inclusive Scan Result:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", h_out[i]);
    }
    printf("\n");
    return 0;
}