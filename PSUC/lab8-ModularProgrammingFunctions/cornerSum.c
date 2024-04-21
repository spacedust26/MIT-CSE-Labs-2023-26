//find the sum of the elements of the 4 corners of a matrix
#include<stdio.h>

int cornerSum(int m, int n, int arr[][20]){
  return arr[0][0] + arr[0][n-1] + arr[m-1][0] + arr[m-1][n-1];
}

int main(){
  int m,n, arr[20][20];
  printf("Enter dimensions of matrix: ");
  scanf("%d %d",&m, &n);
  printf("Enter matrix elements: ");
  for(int i = 0 ; i < m ; i++){
    for(int j = 0; j < n ; j++){
      scanf("%d",&arr[i][j]);
    }
  }
  printf("Corner sum = %d", cornerSum(m,n,arr));
  return 0;
}