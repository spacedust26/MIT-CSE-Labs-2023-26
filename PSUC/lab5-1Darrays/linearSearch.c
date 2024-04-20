//search an element in a 1D array using linear search
#include<stdio.h>

int main(){
  int n, k, i;
  int arr[20];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter element to be searched: ");
  scanf("%d",&k);
  for(i = 0 ; i < n ; i++){
    if(arr[i] == k){
      printf("Element found");
      break;
    }
  }
  if(i == n) printf("Element not found");
  return 0;
}