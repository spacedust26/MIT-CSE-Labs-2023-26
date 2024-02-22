//Finding the maximum element in the array
//Input - integer array A[0, n-1]
//Ouput - maximum element in the array
//Time complexity - O(n)

#include<stdio.h>

//Maximum element function
int maxElement(int arr[],int n){
  int max = 0, i = 0;
  while(i < n){
    if(arr[i] > max){
      max = arr[i];
    }
    i++;
  }
  return max;
}

//Main function
void main(){
  int n, arr[20];
  printf("Enter the array size: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i  = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  int max = maxElement(arr,n);
  printf("Maximum element in the array is %d.",max);
}