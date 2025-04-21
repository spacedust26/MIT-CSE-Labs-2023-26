// Additional Exercise 1 - Write a CUDA program that reads a M X N matrix A and produces a resultant matrix B of same size as follows: Replcae all the even numbered matrix elements with their row sum and odd numbered elements with their column sum.
// example: A = 1 2 3           B =  5 6 9
//              4 5 6                15 7 15

#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#define M 2
#define N 3

__global__ void processMatrix(int *A, int *B, int *rowSum, int *colSum, int rows, int cols) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < rows && col < cols) {
        int idx = row * cols + col;
        if (A[idx] % 2 == 0)
            B[idx] = rowSum[row];
        else
            B[idx] = colSum[col];
    }
}

int main() {
    int A[M][N] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int B[M][N];
    int rowSum[M] = {0};
    int colSum[N] = {0};

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            rowSum[i] += A[i][j];
            colSum[j] += A[i][j];
        }

    int *d_A, *d_B, *d_rowSum, *d_colSum;
    size_t sizeMatrix = M * N * sizeof(int);
    cudaMalloc((void**)&d_A, sizeMatrix);
    cudaMalloc((void**)&d_B, sizeMatrix);
    cudaMalloc((void**)&d_rowSum, M * sizeof(int));
    cudaMalloc((void**)&d_colSum, N * sizeof(int));

    cudaMemcpy(d_A, A, sizeMatrix, cudaMemcpyHostToDevice);
    cudaMemcpy(d_rowSum, rowSum, M * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_colSum, colSum, N * sizeof(int), cudaMemcpyHostToDevice);

    dim3 blockDim(16, 16);
    dim3 gridDim((N + 15) / 16, (M + 15) / 16);

    processMatrix<<<gridDim, blockDim>>>(d_A, d_B, d_rowSum, d_colSum, M, N);

    cudaMemcpy(B, d_B, sizeMatrix, cudaMemcpyDeviceToHost);

    printf("Resulting Matrix B:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    cudaFree(d_A);
    cudaFree(d_B);
}
