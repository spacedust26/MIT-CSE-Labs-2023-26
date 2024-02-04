//Sort an array using bubble sort
//Input - An array[0, n-1] of orderable elements
//Output - An arary[0, n-1] sorted in ascending order
//Time complexity - O(n^2)

#include<stdio.h>

//Bubble sort
void bubbleSort(int *arr, int n){
  int opcount = 0;
  for(int i = 0 ; i < n-1 ; i++){
    for(int j = 0 ; j < n-i-1 ; j++){
      opcount++;
      if(arr[j+1] < arr[j]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
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
  printf("\nAfter bubble sort: ");
  bubbleSort(arr,n);
  for(int i=0 ; i < n ; i++){
    printf("%d ",arr[i]);
  }
  return 0;
}