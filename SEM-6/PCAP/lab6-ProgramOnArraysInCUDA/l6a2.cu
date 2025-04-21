// Additional Exercise 2 - Write a CUDA program which takes N binary numbers as input and stores the one's complement of each element in another array in parallel

#include <stdio.h>
#include <string.h>
#include <cuda_runtime.h>

#define MAX_LEN 32  // Max binary string length

__global__ void onesComplementKernel(char *d_input, char *d_output, int N, int maxLen) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < N) {
        int offset = idx * maxLen;
        for (int i = 0; i < maxLen; i++) {
            char bit = d_input[offset + i];
            if (bit == '\0') {
                d_output[offset + i] = '\0';  // End of string
                break;
            } else if (bit == '0') {
                d_output[offset + i] = '1';
            } else if (bit == '1') {
                d_output[offset + i] = '0';
            } else {
                d_output[offset + i] = bit; // Just in case of invalid input
            }
        }
    }
}

int main() {
    int N;
    printf("Enter the number of binary numbers: ");
    scanf("%d", &N);
    getchar(); // to consume newline after scanf

    const int maxLen = MAX_LEN + 1;  // +1 for null terminator
    char *h_input = new char[N * maxLen];
    char *h_output = new char[N * maxLen];

    printf("Enter %d binary strings:\n", N);
    for (int i = 0; i < N; i++) {
        char temp[MAX_LEN + 1];
        fgets(temp, maxLen, stdin);
        temp[strcspn(temp, "\n")] = '\0'; // remove newline
        strncpy(&h_input[i * maxLen], temp, maxLen);
    }

    char *d_input, *d_output;
    cudaMalloc(&d_input, N * maxLen);
    cudaMalloc(&d_output, N * maxLen);

    cudaMemcpy(d_input, h_input, N * maxLen, cudaMemcpyHostToDevice);

    int threads = 256;
    int blocks = (N + threads - 1) / threads;

    onesComplementKernel<<<blocks, threads>>>(d_input, d_output, N, maxLen);
    cudaDeviceSynchronize();

    cudaMemcpy(h_output, d_output, N * maxLen, cudaMemcpyDeviceToHost);

    printf("\nOne's Complement:\n");
    for (int i = 0; i < N; i++) {
        printf("%s -> %s\n", &h_input[i * maxLen], &h_output[i * maxLen]);
    }

    // Free memory
    delete[] h_input;
    delete[] h_output;
    cudaFree(d_input);
    cudaFree(d_output);

    return 0;
}
