#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cuda_runtime.h>
void intswap(int &A, int &B) {
    int temp = A;
    A = B;
    B = temp;
}

__global__ void sort(int *c, int *count) {
    int l;
    if (*count % 2 == 0)
        l = *count / 2;
    else
        l = (*count / 2) + 1;

    for (int i = 0; i < l; i++) {
        if (threadIdx.x < (*count - 1)) {
            if (c[threadIdx.x] > c[threadIdx.x + 1])
                intswap(c[threadIdx.x], c[threadIdx.x + 1]);
        }

        if (threadIdx.x < (*count - 1)) {
            if (c[threadIdx.x] > c[threadIdx.x + 1])
                intswap(c[threadIdx.x], c[threadIdx.x + 1]);
        }

    } 
}

int main() {
    int *a, *b;
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int N = sizeof(int) * n;
    a = (int *)malloc(N);
    b = (int *)malloc(N);
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *d_A, *count;
    cudaMalloc(&d_A, N);
    cudaMalloc((void **)&count, sizeof(int));
    cudaMemcpy(d_A, a, N, cudaMemcpyHostToDevice);
    cudaMemcpy(count, &n, sizeof(int), cudaMemcpyHostToDevice);
    
    sort<<<1, n>>>(d_A, count);
    
    cudaMemcpy(b, d_A, N, cudaMemcpyDeviceToHost); 
    printf("\nSORTED ARRAY: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");

    free(a);
    free(b);
    cudaFree(d_A);
    cudaFree(count);

    return 0;
}
