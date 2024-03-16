//Implements sequential search with a search key as a sentinel
//Input - an array of n elements and a search key k
//Output - the index of the first element in A[0,..n-1] whose value is equal to k or -1 if no such element is found
//Time complexity - O(n)

#include<stdio.h>

//Sequential search function
int sequentialSearch(int arr[], int n, int key){
  for(int i = 0 ; i < n ; i++){
    if(arr[i] == key) return i;
  }
  return -1;
}

//Main function
int main(){
  int n, arr[20],key;
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter element to be found: ");
  scanf("%d",&key);
  int s = sequentialSearch(arr,n,key);
  if(s == -1) printf("Element not found.");
  else printf("Element found at index %d.",s);
  return 0;
}