//to interchange the primary and secondary diagonal elements in a matrix
#include<stdio.h>

int main(){
  int m,n;
  int arr[20][20];
  printf("Enter matrix dimensions: ");
  scanf("%d %d", &m, &n);
  if(n != m)printf("Not a square matrix");
  else{
    printf("Enter matrix elements: ");
    for(int i = 0 ; i < m ; i++){
      for(int j = 0 ; j < n; j++){
        scanf("%d", &arr[i][j]);
      }
    }
    for(int i = 0; i < n ; i++){
      int temp = arr[i][i];
      arr[i][i] = arr[i][n-i-1];
      arr[i][n-i-1] = temp;
    }
    for(int i = 0 ; i < m ; i++){
      for(int j = 0 ; j < n; j++){
        printf("%d ", arr[i][j]);
      }
      printf("\n");
    }
  }
}