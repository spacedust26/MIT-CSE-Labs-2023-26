//To sort a set of integers using comparison counting
//Input - an array of integers A[0,...n-1]
//Output - sorted array
//Time complexity - O(n^2)

#include<stdio.h>

//Comparison count function
void comparisonCount(int *arr, int n){
  int count[30];
  for(int i = 0 ; i < n ; i++){
    count[i] = 0;
  }
  for(int i = 0 ; i < n -1 ; i++){
    for(int j = i + 1 ; j < n ; j++){
      if(arr[i] > arr[j]) count[i]++;
      else count[j]++;
    }
  }
  int newarr[30];
  for(int i = 0 ; i < n ; i++){
    newarr[count[i]] = arr[i];
  }
  for(int i = 0 ; i < n ; i++){
    arr[i] = newarr[i];
  }
}

//Main function
int main(){
  int n, arr[30];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  comparisonCount(arr,n);
  printf("Sorted array: ");
  for(int i = 0 ; i < n ; i++){
    printf("%d ",arr[i]);
  }
}