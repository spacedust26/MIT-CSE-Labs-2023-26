//Sort a given array using insertion sort
//Input - an array A[0..n-1] of n orderable elements
//Output - array A[0..n-1] sorted in ascending order
//Time complexity - worst case O(n^2), best case omega(n), average case theta(n^2)

#include<stdio.h>

//Insertion sort function
void insertionSort(int *arr, int n){
  for(int i = 1 ; i < n ; i++){
    int v = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>v){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = v;
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
  insertionSort(arr,n);
  printf("Insertion sort: ");
  for(int i = 0 ; i < n ; i++){
    printf("%d ",arr[i]);
  }
  return 0;
}

