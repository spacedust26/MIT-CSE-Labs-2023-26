// Solved Exercise - Write a program in CUDA to find the transpose of a matrix in parallel

#include <stdio.h>
#include <stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void transpose(int* input, int* output, int rows, int cols) {
    int x = blockIdx.x * blockDim.x + threadIdx.x; // column index
    int y = blockIdx.y * blockDim.y + threadIdx.y; // row index
    if (x < cols && y < rows) {
        output[x * rows + y] = input[y * cols + x];
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int size = rows * cols;
    int* h_input = (int*)malloc(size * sizeof(int));
    int* h_output = (int*)malloc(size * sizeof(int));
    printf("Enter %d elements (row-wise):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &h_input[i]);
    }

    int *d_input, *d_output;
    cudaMalloc((void**)&d_input, size * sizeof(int));
    cudaMalloc((void**)&d_output, size * sizeof(int));
    cudaMemcpy(d_input, h_input, size * sizeof(int), cudaMemcpyHostToDevice);
    dim3 threadsPerBlock(16, 16);
    dim3 blocksPerGrid((cols + 15) / 16, (rows + 15) / 16);
    transpose<<<blocksPerGrid, threadsPerBlock>>>(d_input, d_output, rows, cols);
    cudaMemcpy(h_output, d_output, size * sizeof(int), cudaMemcpyDeviceToHost);

    printf("\nTransposed Matrix (%dx%d):\n", cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", h_output[i * cols + j]);
        }
        printf("\n");
    }

    cudaFree(d_input);
    cudaFree(d_output);
    free(h_input);
    free(h_output);
    return 0;
}
