//To perform matrix multiplication of two n X n matrices
//Input - number of rows/column n and two n X n matrix A and B
//Output - product matrix C = AB

#include<stdio.h>
#include<stdlib.h>

//Product function
int **multiply(int A[][30], int B[][30], int n){
  int **C = (int **) malloc (n * sizeof(int*));
  for(int i  = 0 ;i <n ; i++){
    C[i] = (int *)calloc(n, sizeof(int));
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      C[i][j] = 0;
      for(int k = 0 ; k < n ; k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}
//Main function
void main(){
  int n, A[30][30], B[30][30];
  printf("Enter n: ");
  scanf("%d",&n);
  printf("Enter matrix A elements: ");
  for(int i = 0; i < n; i++){
    for(int j = 0 ; j < n ; j++){
      scanf("%d",&A[i][j]);
    }
  }
  printf("Enter matrix B elements: ");
  for(int i = 0; i < n; i++){
    for(int j = 0 ; j < n ; j++){
      scanf("%d",&B[i][j]);
    }
  }
  int **C = multiply(A,B,n);
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      printf("%d ",C[i][j]);
    }
    printf("\n");
  }
}
