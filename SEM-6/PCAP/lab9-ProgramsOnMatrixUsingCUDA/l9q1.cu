// Lab Exercise 1 - Write a program in CUDA to perform parallele Sparse Matrix - Vector multiplication using compressed sparse row (CSR) storage format. Represent the input sparse matrix in CSR format in the host code
 
#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>
 
__global__ void csr_kernel(int num_rows, int *row_ptr, int *col_index, int *data, int *x, int *y) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < num_rows) {
        int dot = 0;
        int row_start = row_ptr[row];
        int row_end = row_ptr[row + 1];
        for (int i = row_start; i < row_end; i++) {
            dot += data[i] * x[col_index[i]];
        }
        y[row] = dot;
    }
}
 
int main(){
    int num_rows, num_cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &num_rows, &num_cols);
    int matrix[num_rows][num_cols];
    int num_non_zeros = 0;
    printf("Enter the sparse matrix (%dx%d):\n", num_rows, num_cols);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) num_non_zeros++;
        }
    }
 
    int data[num_non_zeros];
    int col_index[num_non_zeros];
    int row_ptr[num_rows + 1];
 
    // Convert matrix to CSR format
    row_ptr[0] = 0;
    int idx = 0;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (matrix[i][j] != 0) {
                data[idx] = matrix[i][j];
                col_index[idx] = j;
                idx++;
            }
        }
        row_ptr[i + 1] = idx;
    }
    int x[num_cols];
    printf("Enter vector x (%d values):\n", num_cols);
    for (int i = 0; i < num_cols; i++) scanf("%d", &x[i]);
    int y[num_rows];
    int *d_row_ptr, *d_col_index;
    int *d_data, *d_x, *d_y;
    cudaMalloc((void**)&d_row_ptr, (num_rows + 1) * sizeof(int));
    cudaMalloc((void**)&d_col_index, num_non_zeros * sizeof(int));
    cudaMalloc((void**)&d_data, num_non_zeros * sizeof(int));
    cudaMalloc((void**)&d_x, num_cols * sizeof(int));
    cudaMalloc((void**)&d_y, num_rows * sizeof(int));
    cudaMemcpy(d_row_ptr, row_ptr, (num_rows + 1) * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_col_index, col_index, num_non_zeros * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_data, data, num_non_zeros * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_x, x, num_cols * sizeof(int), cudaMemcpyHostToDevice);
    int block_size = 256;
    int grid_size = (num_rows + block_size - 1) / block_size;
    csr_kernel<<<grid_size, block_size>>>(num_rows, d_row_ptr, d_col_index, d_data, d_x, d_y);
    cudaMemcpy(y, d_y, num_rows * sizeof(int), cudaMemcpyDeviceToHost);
 
    printf("CSR Representation:\n");
    printf("Data Array: ");
    for (int i = 0; i < num_non_zeros; i++) printf("%d ", data[i]);
    printf("\nCol_index Array: ");
    for (int i = 0; i < num_non_zeros; i++) printf("%d ", col_index[i]);
    printf("\nRow_ptr Array: ");
    for (int i = 0; i <= num_rows; i++) printf("%d ", row_ptr[i]);
    printf("\n");
    printf("\nResult vector y:\n");
    for (int i = 0; i < num_rows; i++)printf("%d\n", y[i]);
 
    cudaFree(d_row_ptr);
    cudaFree(d_col_index);
    cudaFree(d_data);
    cudaFree(d_x);
    cudaFree(d_y);
    return 0;
}
 