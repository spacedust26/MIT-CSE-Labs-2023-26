// Lab Exercise 3 - Write a CUDA program that reads a matrix A of size M X N and produce an output matrix B of the same size such that it replaces all the non border elements (numbers in bold) of A with its equivalent 1's complement and remaining elements same as matrix A.
 
#include<stdio.h>
#include <cuda_runtime.h>
 
__global__ void processMatrix(int *A, int *B, int M, int N) {
    int row = threadIdx.y;
    int col = threadIdx.x;
    if (row < M && col < N) {
        int index = row * N + col;
        if (row == 0 || row == M - 1 || col == 0 || col == N - 1) {
            B[index] = A[index];
        } else {
            B[index] = ~A[index];
        }
    }
}
 
void printBinary(int num) {
    for (int i = 2; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}
 
int main() {
    int M, N;
    printf("Enter M and N: ");
    scanf("%d %d", &M, &N);
 
    int size = M * N * sizeof(int);
    int *h_A = (int *)malloc(size);
    int *h_B = (int *)malloc(size);
 
    printf("Enter matrix elements:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &h_A[i * N + j]);
        }
    }
 
    int *d_A, *d_B;
    cudaMalloc((void **)&d_A, size);
    cudaMalloc((void **)&d_B, size);
 
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    dim3 threadsPerBlock(N, M);
    processMatrix<<<1, threadsPerBlock>>>(d_A, d_B, M, N);
    cudaMemcpy(h_B, d_B, size, cudaMemcpyDeviceToHost);
 
    printf("Result (in binary):\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1) printf("%d", h_B[i * N  + j]);
            else printBinary(h_B[i * N + j]);
            printf(" ");
        }
        printf("\n");
    }
 
    free(h_A);
    free(h_B);
    cudaFree(d_A);
    cudaFree(d_B);
 
    return 0;
}