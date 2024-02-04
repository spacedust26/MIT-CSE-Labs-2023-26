//Sorts a given arary using selection sort
//Input - An array A[0, n-1] of orderable elements
//Output - An array A[0, n-1] sorted in ascending order
//Time complexity - O(n^2)

#include<stdio.h>

//Selection Sort
void selectionSort(int *arr, int n){
  int opcount = 0;
  for(int i = 0 ; i < n-1 ; i++){
    int min = i;
    for(int j = i+1 ; j < n ; j++){
      opcount++;
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
  printf("\nOpcount = %d\n",opcount);
}

//Main function
int main(){
  int n, arr[40];
  printf("Enter size: ");
  scanf("%d",&n);
  printf("Enter arary elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("\nAfter selection sort: ");
  selectionSort(arr,n);
  for(int i=0 ; i < n ; i++){
    printf("%d ",arr[i]);
  }
  return 0;
}