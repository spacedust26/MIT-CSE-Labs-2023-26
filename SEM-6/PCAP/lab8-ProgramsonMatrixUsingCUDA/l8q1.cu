// Lab Exercise 1
// Write a program in CUDA to add two Matrices for the following specifications
// a. Each row of the resultant matrix to be computed by one thread
// b. Each column of resultant matrix to be computed by one thread
// c. Ecah element of resultant matrix to be computed by one thread

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

__global__ void addMatrixByRow(int *a, int *b, int *c, int m, int n){
    int row = threadIdx.x;
    if(row < m){
        for(int col = 0; col < n; col++){
            c[row * n + col] = a[row * n + col] + b[row * n + col];
        }
    }
}

__global__ void addMatrixByColumn(int *a, int *b, int *c, int m, int n){
    int col = threadIdx.x;
    if(col < n){
        for(int row = 0; row < m; row++){
            c[row * n + col] = a[row * n + col] + b[row * n + col];
        }
    }
}

__global__ void addMatrixByElement(int *a, int *b, int *c, int m, int n) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (row < m && col < n) {
        c[row * n + col] = a[row * n + col] + b[row * n + col];
    }
}

void printMatrix(int *m, int m_rows, int n_cols){
    for(int i = 0; i < m_rows; i++){
        for(int j = 0; j < n_cols; j++){
            printf("%d\t", m[i*n_cols + j]);
        }
        printf("\n");
    }
}

int main(){
    int *h_a, *h_b, *h_c, m, n, *d_a, *d_b, *d_c;
    printf("Enter the number of rows (m) of the matrices: ");
    scanf("%d", &m);
    printf("Enter the number of columns (n) of the matrices: ");
    scanf("%d", &n);
    
    h_a = (int*)malloc(m * n * sizeof(int));
    h_b = (int*)malloc(m * n * sizeof(int));
    h_c = (int*)malloc(m * n * sizeof(int));
    
    printf("Enter the elements for matrix A: ");
    for(int i = 0; i < m*n; i++) scanf("%d", &h_a[i]);
    
    printf("Enter the elements for matrix B: ");
    for(int i = 0; i < m*n; i++) scanf("%d", &h_b[i]);

    cudaMalloc((void**)&d_a, m * n * sizeof(int));
    cudaMalloc((void**)&d_b, m * n * sizeof(int));
    cudaMalloc((void**)&d_c, m * n * sizeof(int));

    cudaMemcpy(d_a, h_a, m * n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, m * n * sizeof(int), cudaMemcpyHostToDevice);

    // Row-wise computation
    addMatrixByRow<<<1, m>>>(d_a, d_b, d_c, m, n);
    cudaMemcpy(h_c, d_c, m * n * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Resultant matrix after row-wise computation:\n");
    printMatrix(h_c, m, n);

    // Column-wise computation
    addMatrixByColumn<<<1, n>>>(d_a, d_b, d_c, m, n);
    cudaMemcpy(h_c, d_c, m * n * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Resultant matrix after column-wise computation:\n");
    printMatrix(h_c, m, n);

    // Element-wise computation
    dim3 threadsPerBlock(16, 16); 
    dim3 numBlocks((n + threadsPerBlock.x - 1) / threadsPerBlock.x, (m + threadsPerBlock.y - 1) / threadsPerBlock.y);                   
    addMatrixByElement<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c, m, n);
    cudaMemcpy(h_c, d_c, m * n * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Resultant matrix after element-wise computation:\n");
    printMatrix(h_c, m, n);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    free(h_a);
    free(h_b);
    free(h_c);

    return 0;
}
