// Lab Exercide 2 - Write a program in CUDA to read M X N matrix A and replace 1st row of this matrix by same elements, 2nd row elements by square of each element and 3rd row elements by cube of each element and so on.
 
#include <stdio.h>
#include <cuda_runtime.h>
#include <math.h>
 
__global__ void transformMatrix(int *A, int M, int N) {
    int row = threadIdx.x;
    if (row < M) {
        for (int col=0; col<N; col++) {
            A[row * N + col] = pow(A[row * N + col],(row + 1));
        }
    }
}
 
int main() {
    int M, N;
    printf("Enter M and N: ");
    scanf("%d %d", &M, &N);
    int size = M * N * sizeof(int);
    int *h_A = (int*)malloc(size);
    printf("Enter matrix elements:\n");
    for (int i = 0; i < M * N; i++) {
        scanf("%d", &h_A[i]);
    }
    int *d_A;
    cudaMalloc(&d_A, size);
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    transformMatrix<<<1, M>>>(d_A, M, N);
    cudaMemcpy(h_A, d_A, size, cudaMemcpyDeviceToHost);
    printf("Result:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", h_A[i * N + j]);
        }
        printf("\n");
    }
    free(h_A);
    cudaFree(d_A);
    return 0;
}