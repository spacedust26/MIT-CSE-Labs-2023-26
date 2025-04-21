// Additional Exercise 1 - write a program in CUDA which takes N integers as input. It converts these integers into their corresponding octal values and stores the result in another array in parallel

#include <stdio.h>
#include <cuda_runtime.h>

__device__ void intToOctal(int num, char *result) {
    int index = 0;
    int octal[32];
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    while (num > 0) {
        octal[index++] = num % 8;
        num /= 8;
    }
    for (int i = 0; i < index; i++) {
        result[i] = '0' + octal[index - i - 1];
    }
    result[index] = '\0'; 
}

__global__ void convertToOctal(int *d_input, char *d_output, int N, int maxLen) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < N) {
        intToOctal(d_input[idx], &d_output[idx * maxLen]);
    }
}

int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    int *h_input = new int[N];
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) scanf("%d", &h_input[i]);

    int *d_input;
    char *d_output;
    const int maxLen = 12;  // Max octal length for 32-bit int + null char
    char *h_output = new char[N * maxLen];
    cudaMalloc(&d_input, sizeof(int) * N);
    cudaMalloc(&d_output, sizeof(char) * N * maxLen);
    cudaMemcpy(d_input, h_input, sizeof(int) * N, cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocks = (N + threadsPerBlock - 1) / threadsPerBlock;
    convertToOctal<<<blocks, threadsPerBlock>>>(d_input, d_output, N, maxLen);
    cudaDeviceSynchronize();
    cudaMemcpy(h_output, d_output, sizeof(char) * N * maxLen, cudaMemcpyDeviceToHost);
    printf("\nOctal representations:\n");
    for (int i = 0; i < N; i++) {
        printf("%d -> %s\n", h_input[i], &h_output[i * maxLen]);
    }

    // Cleanup
    delete[] h_input;
    delete[] h_output;
    cudaFree(d_input);
    cudaFree(d_output);

    return 0;
}
