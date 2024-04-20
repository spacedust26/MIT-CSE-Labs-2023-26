//print all the prime numbers in a given 1D array
#include<stdio.h>

int main(){
  int n, count;
  int arr[20];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("Prime numbers in the given array are: ");
  for(int i = 0 ; i < n ; i++){
    count = 1;
    for(int j = 2 ; j < arr[i] ; j++){
      if(arr[i] % j == 0){
        count = 0;
        break;
      }
    }
    if(count == 1) printf("%d ",arr[i]);
  }
  return 0;
}