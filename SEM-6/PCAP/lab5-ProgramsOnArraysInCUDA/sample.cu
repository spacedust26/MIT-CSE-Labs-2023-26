 //Solved Exercise: Program to add two numbers
 
 #include "cuda_runtime.h"
 #include "device_launch_parameters.h"
 #include<stdio.h>

__global__ void add(int *a, int *b, int *c){
    *c = *a + *b;
}

int main(){
    int a,b,c; //host copies
    int *d_a, *d_b, *d_c; //device copies
    int size = sizeof(int);
    
    //allocate space for device copies
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    //setup input values
    a=5, b = 5;;

    //copy inputs to device
    cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

    //launch add() kernal on GPU
    add<<<1,1>>>(d_a, d_b, d_c); // 1 block 1 thread

    //copy results back to host
    cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
    printf("Result : %d\n", c);

    //cleanup
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    return 0;
}
