// Additional Exercise 2 - Write a CUDA program that reads a character type matrix A and integer type matrix B of size M X N. It produces an output string STR such that, every character of A is repeated r times (where r is the integer value in matrix B which is having the same index as that of the character taken in A). Write the kernel such that every value of input matrix must be produced required number of times by one thread.
// Example : A = [[p, C, a, P][e, X, a, M]]
// B = [[1, 2, 4, 3][2, 4, 3, 2]]
// Output String STR: pCCaaaaPPPeeXXXXaaaMM

#include <stdio.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#define M 2
#define N 4
#define MAX_LEN 1000 

__device__ int getOffset(int* B, int row, int col, int rows, int cols) {
    int offset = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < cols; j++)
            offset += B[i * cols + j];
    for (int j = 0; j < col; j++)
        offset += B[row * cols + j];
    return offset;
}
__global__ void repeatChars(char* A, int* B, char* STR, int rows, int cols) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < rows && col < cols) {
        int idx = row * cols + col;
        char ch = A[idx];
        int r = B[idx];
        int offset = getOffset(B, row, col, rows, cols);
        for (int i = 0; i < r; i++) {
            STR[offset + i] = ch;
        }
    }
}

int main() {
    char A[M][N] = {
        {'p', 'C', 'a', 'P'},
        {'e', 'X', 'a', 'M'}
    };

    int B[M][N] = {
        {1, 2, 4, 3},
        {2, 4, 3, 2}
    };
    char flatA[M * N];
    int flatB[M * N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            flatA[i * N + j] = A[i][j];
            flatB[i * N + j] = B[i][j];
        }

    int totalLen = 0;
    for (int i = 0; i < M * N; i++) {
        totalLen += flatB[i];
    }

    char *d_A, *d_STR;
    int *d_B;
    cudaMalloc((void**)&d_A, M * N * sizeof(char));
    cudaMalloc((void**)&d_B, M * N * sizeof(int));
    cudaMalloc((void**)&d_STR, totalLen * sizeof(char));
    cudaMemcpy(d_A, flatA, M * N * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, flatB, M * N * sizeof(int), cudaMemcpyHostToDevice);
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((N + 15) / 16, (M + 15) / 16);
    repeatChars<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_STR, M, N);
    char STR[MAX_LEN] = {0};
    cudaMemcpy(STR, d_STR, totalLen * sizeof(char), cudaMemcpyDeviceToHost);
    STR[totalLen] = '\0';
    printf("Output STR: %s\n", STR);

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_STR);
    return 0;
}
