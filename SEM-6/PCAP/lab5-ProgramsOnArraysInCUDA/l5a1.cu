// Additional Exercise - Write a program in CUDA to perform linear algebra function of the form y = ax+y where x and y are vectors and a is a scalar value

#include <stdio.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

const int n = 5;

__global__ void linearfunction(int *x, int *y, int *a){
    int tid = blockDim.x * blockIdx.x + threadIdx.x;
    if(tid < n) y[tid] = *a * x[tid] + y[tid];
}

int main(){
    int x[n], y[n], a;
    printf("Enter %d elements of vector x: ", n);
    for(int i=0;i<n;i++) scanf("%d", &x[i]);
    printf("Enter %d elements of vector y: ", n);
    for(int i=0;i<n;i++) scanf("%d", &y[i]);
    printf("Enter value of scalar a: ");
    scanf("%d", &a);

    // int x[n]= {1,2,3,4,5};
    // int y[n]= {7,2,3,8,5};
    // int a = 2;

    int *d_x, *d_y, *d_a;
    cudaMalloc((void**)&d_x, n * sizeof(int));
    cudaMalloc((void**)&d_y, n * sizeof(int));
    cudaMalloc((void**)&d_a, sizeof(int));
    cudaMemcpy(d_x, x, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_a, &a, sizeof(int), cudaMemcpyHostToDevice);

    linearfunction<<<n, 1>>>(d_x, d_y, d_a);
    cudaMemcpy(y, d_y, n * sizeof(int), cudaMemcpyDeviceToHost);
    printf("Resultant vector: ");
    for(int i=0;i<n;i++) printf("%d ", y[i]);

    cudaFree(d_x);
    cudaFree(d_y);
    cudaFree(d_a);
    return 0;
}