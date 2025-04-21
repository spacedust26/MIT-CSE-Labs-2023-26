// Exercise 1 - Write a program in CUDA which performs convolution operation on one-dimensional input array N of size width using a mask array M of size mask_width to produce the resultant one dimensional array P of size width

#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void convolution1d(int *n, int *m , int *p, int *width, int *mask_width){
    int i = threadIdx.x;
    int pvalue = 0;
    int n_start_point = i - (*mask_width / 2);
    for(int j=0; j<*mask_width;j++){
        if(n_start_point+j >= 0 && n_start_point+j < *width){
            pvalue += n[n_start_point + j] * m[j];
        }
    }
    p[i] = pvalue;
}

int main(){
    const int width = 10;
    const int mask_width = 5;
    int N[width] = {1,2,3,4,5,6,7,8,9,10};
    int P[width];
    int M[mask_width] = {2,3,5,7,1};

    int *d_N, *d_M, *d_P, *d_width, *d_mask_width;
    cudaMalloc((void**)&d_N, width * sizeof(int));
    cudaMalloc((void**)&d_P, width * sizeof(int));
    cudaMalloc((void**)&d_M, mask_width * sizeof(int));
    cudaMalloc((void**)&d_width, sizeof(int));
    cudaMalloc((void**)&d_mask_width, sizeof(int));

    cudaMemcpy(d_N, N, width * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_M, M, mask_width * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_width, &width, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_mask_width, &mask_width, sizeof(int), cudaMemcpyHostToDevice);

    convolution1d<<<1, width>>>(d_N, d_M, d_P, d_width, d_mask_width);
    cudaMemcpy(P, d_P, width*sizeof(width), cudaMemcpyDeviceToHost);
    printf("Resultant array after convolution: ");
    for(int i=0;i<width;i++) printf("%d ", P[i]);

    cudaFree(d_N);
    cudaFree(d_P);
    cudaFree(d_M);
    cudaFree(d_width);
    cudaFree(d_mask_width);
    return 0;
}
