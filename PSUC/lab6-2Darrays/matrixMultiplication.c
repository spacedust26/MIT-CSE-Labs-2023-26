//To perform matrix multiplication
#include<stdio.h>
#include<stdlib.h>

int main(){
  int m,n,p,q;
  int arr[20][20], brr[20][20], crr[20][20];
  printf("Enter matrix A dimensions: ");
  scanf("%d %d", &m, &n);
  printf("Enter matrix B dimensions: ");
  scanf("%d %d", &p, &q);
  if(n != p){
    printf("Dimensions of the 2 matrix incompatible for multiplication.");
    exit(0);
  }
  printf("Enter matrix A elements: ");
  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  printf("Enter matrix B elements: ");
  for(int i = 0 ; i < p ; i++){
    for(int j = 0 ; j < q; j++){
      scanf("%d", &brr[i][j]);
    }
  }
  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < q ; j++){
      crr[i][j] = 0;
      for(int k = 0 ; k < n ; k++){
        crr[i][j] += arr[i][k] * brr[k][j];
      }
    }
  }
  printf("The resultant matrix is:\n");
   for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < q; j++){
      printf("%d ", crr[i][j]);
    }
    printf("\n");
  }
  return 0;
}