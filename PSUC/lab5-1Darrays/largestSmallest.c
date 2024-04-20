//find the largest and smallest element in a 1D array
#include<stdio.h>

int main(){
  int n;
  int arr[20];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  int max = arr[0];
  int min = arr[0];
  for(int i = 1 ; i < n ; i++){
    if(arr[i] < min) min = arr[i];
    if(arr[i] > max) max = arr[i];
  }
  printf("Largest element = %d\nSmallest element = %d", max,min);
  return 0;
}