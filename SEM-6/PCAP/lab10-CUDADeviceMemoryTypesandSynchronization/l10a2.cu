// Additional exercise 2 - write a program in CUDA to perform tiled 1D convolution operation on the input array N of size width using the mask array, M of size mask_width to produce the output array, P of size width

#include <stdio.h>
#include <cuda_runtime.h>

#define MASK_WIDTH 3
#define TILE_WIDTH 8
#define RADIUS (MASK_WIDTH / 2)

// Constant memory for mask
__constant__ float M[MASK_WIDTH];

// 1D Convolution kernel using shared memory
__global__ void convolution1D(float* N, float* P, int width) {
    __shared__ float N_s[TILE_WIDTH + MASK_WIDTH - 1];

    int global_idx = blockIdx.x * blockDim.x + threadIdx.x;
    int local_idx = threadIdx.x + RADIUS;

    // Load shared memory with halo
    if (global_idx < width)
        N_s[local_idx] = N[global_idx];
    else
        N_s[local_idx] = 0.0f;

    if (threadIdx.x < RADIUS) {
        // Left halo
        int left_idx = global_idx - RADIUS;
        N_s[threadIdx.x] = (left_idx >= 0) ? N[left_idx] : 0.0f;

        // Right halo
        int right_idx = global_idx + TILE_WIDTH;
        if (threadIdx.x + TILE_WIDTH < TILE_WIDTH + RADIUS)
            N_s[threadIdx.x + TILE_WIDTH + RADIUS] = (right_idx < width) ? N[right_idx] : 0.0f;
    }

    __syncthreads();

    // Perform convolution
    if (global_idx < width) {
        float sum = 0.0f;
        for (int j = 0; j < MASK_WIDTH; j++) {
            sum += M[j] * N_s[local_idx - RADIUS + j];
        }
        P[global_idx] = sum;
    }
}

int main() {
    int width = 16;

    float h_N[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    float h_M[MASK_WIDTH] = {0.25, 0.5, 0.25}; // Sample blur kernel
    float h_P[16];

    float *d_N, *d_P;

    // Allocate device memory
    cudaMalloc((void**)&d_N, width * sizeof(float));
    cudaMalloc((void**)&d_P, width * sizeof(float));

    // Copy data to device
    cudaMemcpy(d_N, h_N, width * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpyToSymbol(M, h_M, MASK_WIDTH * sizeof(float));

    // Kernel launch
    int numBlocks = (width + TILE_WIDTH - 1) / TILE_WIDTH;
    convolution1D<<<numBlocks, TILE_WIDTH>>>(d_N, d_P, width);

    // Copy result back to host
    cudaMemcpy(h_P, d_P, width * sizeof(float), cudaMemcpyDeviceToHost);

    // Print result
    printf("Input:\n");
    for (int i = 0; i < width; i++) {
        printf("%.1f ", h_N[i]);
    }

    printf("\n\nOutput (Convolved):\n");
    for (int i = 0; i < width; i++) {
        printf("%.2f ", h_P[i]);
    }
    printf("\n");

    // Free memory
    cudaFree(d_N);
    cudaFree(d_P);

    return 0;
}
