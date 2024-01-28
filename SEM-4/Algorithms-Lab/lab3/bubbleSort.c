// Write  a  program  to  sort  set  of  integers  using  bubble  sort.  Analyze  its  time efficiency. Obtain the experimental result of order of growth. Plot the result for the best and worst case.
#include<stdio.h>
#include<stdlib.h>
//Bubble sort function
void bubbleSort(int *arr, int n){
  int opcount = 0;
  for(int i=0; i<n-1 ;i++){
    for(int j=0; j<n-i-1; j++){
      opcount++;
      if(arr[j+1]< arr[j]){
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
  int n, arr[50];
  printf("Enter limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i=0; i<n ;i++){
    scanf("%d",&arr[i]);
  }
  printf("After sorting: \n");
  bubbleSort(arr,n);
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}