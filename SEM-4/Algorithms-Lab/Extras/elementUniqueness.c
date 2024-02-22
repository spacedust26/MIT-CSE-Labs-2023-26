//To find if the given array has unique elements
//Input - an intger array A[0, n-1]
//Output - true for unique false for not unique
//Time complexity -  O(n^2)

#include<stdio.h>
#include<stdbool.h>

bool unique(int arr[], int n){
  for(int i  = 0 ; i < n - 1 ; i++){
    for(int j = i + 1 ; j < n ; j++){
      if(arr[i] == arr[j]) return false;
    }
  }
  return true;
}

//Main function
int main(){
  int n, arr[20];
  printf("Enter the array size: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i  = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  bool val = unique(arr, n);
  printf("%s", val ? "true" : "false");
}