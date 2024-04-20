//To find out whether a matrix is symmetric or not
#include<stdio.h>

int main(){
  int m,n, count =1;
  int arr[20][20];
  printf("Enter matrix dimensions: ");
  scanf("%d %d", &m, &n);
  printf("Enter matrix elements: ");
  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  if(m != n) printf("Not a square matrix\n");
  else{
    for(int i = 0 ; i < m ; i++){
      for(int j = 0; j < n ; j++){
        if(arr[i][j] != arr[j][i]){
          count = 0;
          break;
        }
      }
      if(count == 0) break;
    }
    if(count == 0) printf("Not symmetric");
    else printf("Symmetric");
  }
  return 0;
}