// Additional Exercise 1 - Write a CUDA program which reads an input matrix A of size M X N and produces an output matrix B of size M X N such that, each element of the output matrix is calculated in parallel. Each element, B[i][j], in the output matrix is obtained by adding the elements in ith row and jth column of the input matrix A.
// Example A = [[1, 2, 3], [4, 5, 6]]
// Output B = [[11, 13, 15], [20, 22, 24]]

#include <stdio.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

#define M 2
#define N 3
__global__ void computeMatrix(int* A, int* B, int* rowSum, int* colSum, int rows, int cols) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < rows && col < cols) {
        int idx = row * cols + col;
        B[idx] = rowSum[row] + colSum[col];
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

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) {
            rowSum[i] += A[i][j];
            colSum[j] += A[i][j];
        }

    int size = M * N * sizeof(int);
    int *d_A, *d_B, *d_rowSum, *d_colSum;
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_B, size);
    cudaMalloc((void**)&d_rowSum, M * sizeof(int));
    cudaMalloc((void**)&d_colSum, N * sizeof(int));

    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_rowSum, rowSum, M * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_colSum, colSum, N * sizeof(int), cudaMemcpyHostToDevice);
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((N + 15) / 16, (M + 15) / 16);

    computeMatrix<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_rowSum, d_colSum, M, N);
    cudaMemcpy(B, d_B, size, cudaMemcpyDeviceToHost);

    printf("Output Matrix B:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%d ", B[i][j]);
        printf("\n");
    }

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_rowSum);
    cudaFree(d_colSum);

    return 0;
}
