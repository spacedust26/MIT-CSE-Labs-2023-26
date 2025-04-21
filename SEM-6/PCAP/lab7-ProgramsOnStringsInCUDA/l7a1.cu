// additional Exerice 1 - write a CUDA program which reads a string consisting of N words and reverses each word of it parallel

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>

__global__ void reverseFunction(char *arr, int *startindex, int *endindex){
    int tid = threadIdx.x;
    int start = startindex[tid];
    int end = endindex[tid];

    while(start < end){
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;end--;
    }
}

int main(){
    char str[100] = "hello world hi there";
    char res[100];
    int n = strlen(str);
    int startIndex[100], endIndex[100], totalWords=0;
    int i=0,j=0,k=0;
    while(j < n){
        if(str[j] == ' '){
            startIndex[k] = i;
            endIndex[k++] = j-1;
            i = j + 1;
            totalWords++;
        }
        j++;
    }
    startIndex[k] = i;
    endIndex[k] = j-1;
    totalWords++;

    char *d_str;
    int *d_startIndex, *d_endIndex;
    cudaMalloc((void**)&d_str, n * sizeof(char));
    cudaMalloc((void**)&d_startIndex, k * sizeof(int));
    cudaMalloc((void**)&d_endIndex, k * sizeof(int));
    cudaMemcpy(d_str, str, n * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_startIndex, startIndex, k * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_endIndex, endIndex, k * sizeof(int), cudaMemcpyHostToDevice);

    reverseFunction<<<1, totalWords>>>(d_str, d_startIndex, d_endIndex);
    cudaMemcpy(res, d_str, n * sizeof(char), cudaMemcpyDeviceToHost);
    for(int i=0;i<n;i++) printf("%c", res[i]);

    cudaFree(d_str);
    cudaFree(d_startIndex);
    cudaFree(d_endIndex);
    return 0;
}