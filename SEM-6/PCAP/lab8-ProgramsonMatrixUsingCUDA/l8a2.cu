// Additional Exercise 2 - Write a CUDA program to read a matrix A of size N X N. It replaces the principal diagonal elements with zero. Elements above the principal diagonal by thier factorial and elements below the principal diagonal by their sum of digits.

#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#define N 3

__device__ int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}
__device__ int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
__global__ void processMatrix(int *A, int *B, int n) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row >= n || col >= n) return;
    int idx = row * n + col;
    int val = A[idx];
    if (row == col) B[idx] = 0;
    else if (row < col) B[idx] = factorial(val);
    else B[idx] = sumOfDigits(val);
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[N][N];
    int size = N * N * sizeof(int);
    int *d_A, *d_B;
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_B, size);
    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    dim3 blockDim(16, 16);
    dim3 gridDim((N + 15) / 16, (N + 15) / 16);
    processMatrix<<<gridDim, blockDim>>>(d_A, d_B, N);
    cudaMemcpy(B, d_B, size, cudaMemcpyDeviceToHost);
    printf("Resulting Matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    cudaFree(d_A);
    cudaFree(d_B);
    return 0;
}
