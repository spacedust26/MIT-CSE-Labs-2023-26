//find largest from a given list of numbers
#include<stdio.h>

int largest(int n, int arr[]){
  int max = arr[0];
  for(int i = 1 ; i < n ; i++){
    if(arr[i] > max) max = arr[i];
  }
  return max;
}

int main(){
  int n, arr[20];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("Largest element: %d\n",largest(n, arr));
  return 0;
}