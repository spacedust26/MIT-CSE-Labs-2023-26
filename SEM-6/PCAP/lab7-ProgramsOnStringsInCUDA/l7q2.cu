// Write a CUDA program that reads a string S and produces the string RS as follows:
// Input string S: PCAP Output string RS: PCAPPCAPCP

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>

__global__ void buildRS(char* s, char* rs, int len) {
    int i = threadIdx.x;
    // Calculate starting offset in the output string
    int offset = 0;
    for (int j = 0; j < i; j++) {
        offset += len - j;
    }
    // Copy first (len - i) characters of s to rs at offset
    for (int j = 0; j < len - i; j++) {
        rs[offset + j] = s[j];
    }
}

int main() {
    char s[100];
    printf("Enter string S: ");
    scanf("%s", s);
    int len = strlen(s);

    int rs_len = len * (len + 1) / 2;  // total output size
    char* rs = (char*)malloc((rs_len + 1) * sizeof(char));  // +1 for '\0'
    rs[rs_len] = '\0';

    // Allocate device memory
    char *d_s, *d_rs;
    cudaMalloc((void**)&d_s, len * sizeof(char));
    cudaMalloc((void**)&d_rs, rs_len * sizeof(char));

    cudaMemcpy(d_s, s, len * sizeof(char), cudaMemcpyHostToDevice);

    // Launch kernel
    buildRS<<<1, len>>>(d_s, d_rs, len);
    cudaDeviceSynchronize();

    cudaMemcpy(rs, d_rs, rs_len * sizeof(char), cudaMemcpyDeviceToHost);

    printf("Output string RS: %s\n", rs);

    cudaFree(d_s);
    cudaFree(d_rs);
    free(rs);

    return 0;
}