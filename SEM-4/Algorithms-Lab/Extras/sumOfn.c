//To compute the sum of n numbers using divide and conquer
//Input - array of numbers
//Output - sum of the numbers
//Time complexity - O(n)

#include<stdio.h>
//Sum function
int sum(int *arr, int low, int high){
  if(low == high) return arr[low]; //one element
  else{
    int mid = (low + high) /2;
    int left = sum(arr, low, mid);
    int right = sum(arr, mid+1, high);
    return left + right;
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
  int s = sum(arr, 0, n-1);
  printf("Sum is %d",s);
}