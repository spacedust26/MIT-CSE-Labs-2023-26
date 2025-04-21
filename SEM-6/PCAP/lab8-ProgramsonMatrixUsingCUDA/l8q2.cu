// Lab Exercise 2
// Write a program in CUDA to multiply two matrices for the following specifictaions:
// a. Each row of resultant matrix to be computed by one thread
// b. Each column of resultant matrix to be computed by one thread
// c. Each element of resultant matrix to be computed by one thread

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

__global__ void mulMatrixByRow(int *a, int *b, int *c, int wa, int wb) {
    int row = threadIdx.x;
    for (int col = 0; col < wb; col++) {
        c[row * wb + col] = 0;
        for (int k = 0; k < wa; k++) {
            c[row * wb + col] += a[row * wa + k] * b[k * wb + col];
        }
    }
}

__global__ void mulMatrixByColumn(int *a, int *b, int *c, int ha, int wa) {
    int col = threadIdx.x;
    for (int row = 0; row < ha; row++) {
        c[row * wa + col] = 0;
        for (int k = 0; k < wa; k++) {
            c[row * wa + col] += a[row * wa + k] * b[k * wa + col];
        }
    }
}

__global__ void mulMatrixByElement(int *a, int *b, int *c, int ha, int wb, int wa) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (row < ha && col < wb) {
        c[row * wb + col] = 0;
        for (int k = 0; k < wa; k++) {
            c[row * wb + col] += a[row * wa + k] * b[k * wb + col];
        }
    }
}

void printMatrix(int *m, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", m[i * col + j]);
        }
        printf("\n");
    }
}

int main() {
    int *h_a, *h_b, *h_c, *d_a, *d_b, *d_c;
    int ha, wa, hb, wb;
    
    printf("Enter the dimensions of matrix A: ");
    scanf("%d %d", &ha, &wa);
    printf("Enter the dimensions of matrix B: ");
    scanf("%d %d", &hb, &wb);

    if (wa != hb) {
        printf("Matrix dimensions are incompatible for multiplication.\n");
        return -1;
    }

    h_a = (int*)malloc(ha * wa * sizeof(int));
    h_b = (int*)malloc(hb * wb * sizeof(int));
    h_c = (int*)malloc(ha * wb * sizeof(int));

    printf("Enter the elements for matrix A: ");
    for (int i = 0; i < ha * wa; i++) scanf("%d", &h_a[i]);

    printf("Enter the elements for matrix B: ");
    for (int i = 0; i < hb * wb; i++) scanf("%d", &h_b[i]);

    cudaMalloc((void**)&d_a, ha * wa * sizeof(int));
    cudaMalloc((void**)&d_b, hb * wb * sizeof(int));
    cudaMalloc((void**)&d_c, ha * wb * sizeof(int));

    cudaMemcpy(d_a, h_a, ha * wa * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, hb * wb * sizeof(int), cudaMemcpyHostToDevice);

    // Row-wise matrix multiplication
    mulMatrixByRow<<<1, ha>>>(d_a, d_b, d_c, wa, wb);
    cudaMemcpy(h_c, d_c, ha * wb * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Resultant matrix after row wise computation:\n");
    printMatrix(h_c, ha, wb);

    // Column-wise matrix multiplication
    mulMatrixByColumn<<<1, wb>>>(d_a, d_b, d_c, ha, wa);
    cudaMemcpy(h_c, d_c, ha * wb * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Resultant matrix after column wise computation:\n");
    printMatrix(h_c, ha, wb);

    // Element-wise matrix multiplication
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((wb + threadsPerBlock.x - 1) / threadsPerBlock.x, (ha + threadsPerBlock.y - 1) / threadsPerBlock.y);
    mulMatrixByElement<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c, ha, wb, wa);
    cudaMemcpy(h_c, d_c, ha * wb * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Resultant matrix after element wise computation:\n");
    printMatrix(h_c, ha, wb);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    free(h_a);
    free(h_b);
    free(h_c);

    return 0;
}
