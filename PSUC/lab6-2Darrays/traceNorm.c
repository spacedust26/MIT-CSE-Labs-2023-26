//To find the trace and norm of a given square matrix
// [Hint: Trace= sum of principal diagonal elements 
// Norm= SQRT (sum of squares of the individual elements of an array)] 
#include<stdio.h>
#include<math.h>

int main(){
  int m,n,trace=0;
  float norm=0;
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
      trace += arr[i][i];
    }
    for(int i = 0 ; i < m ; i++){
      for(int j = 0 ; j < n; j++){
        norm += (arr[i][j] * arr[i][j]);
      }
    }
    norm = sqrt(norm);
    printf("Trace = %d\n", trace);
    printf("Norm = %.2f",norm);
  }
  return 0;
}