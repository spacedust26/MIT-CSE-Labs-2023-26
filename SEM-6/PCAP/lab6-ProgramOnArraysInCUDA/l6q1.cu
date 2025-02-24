#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cuda_runtime.h>



__global__ void convulution_1D_basic_kernel(float *N, float *M, float *P,
                                             int Mask_Width, int Width) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  float Pvalue = 0;
  int start_point = i - (Mask_Width / 2);
  for (int j = 0; j < Mask_Width; j++) {
    if (start_point + j >= 0 && start_point + j < Width) {
      Pvalue += N[start_point + j] * M[j];
    }
  }
  if (i < Width) {
    P[i] = Pvalue;
  }
}

int main(int argc, char *argv[]) {
  float *A, *M, *P;
  float *d_A, *d_M, *d_P;
  int arrlen, mask_width;

  printf("Enter number of elements in the array:\n");
  scanf("%d", &arrlen);
  int inp_bytes = arrlen * sizeof(float);
  A = (float *)malloc(inp_bytes);
  P = (float *)malloc(inp_bytes);

  cudaMalloc(&d_A, inp_bytes);
  cudaMalloc(&d_P, inp_bytes);

  printf("Enter the elements:");
  for (int i = 0; i < arrlen; i++) {
    scanf("%f", &A[i]);
  }

  cudaMemcpy(d_A, A, inp_bytes, cudaMemcpyHostToDevice);

  printf("Enter number of elements in the mask:\n");
  scanf("%d", &mask_width);
  int mask_bytes = mask_width * sizeof(float);
  M = (float *)malloc(mask_bytes);
  cudaMalloc(&d_M, mask_bytes);

  printf("Enter the elements in the mask:");
  for (int i = 0; i < mask_width; i++) {
    scanf("%f", &M[i]);
  }

  cudaMemcpy(d_M, M, mask_bytes, cudaMemcpyHostToDevice);

  int threads_per_block = arrlen; 
  int num_blocks = 1;

  convulution_1D_basic_kernel<<<num_blocks, threads_per_block>>>(
      d_A, d_M, d_P, mask_width, arrlen);


  cudaMemcpy(P, d_P, inp_bytes, cudaMemcpyDeviceToHost);

  for (int i = 0; i < arrlen; i++) {
    printf("%f\n", P[i]);
  }
  printf("\n");

  free(M);
  free(A);
  free(P);

  cudaFree(d_M);
  cudaFree(d_A);
  cudaFree(d_P);

  return 0;
}
