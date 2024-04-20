//to sort the elements in ascending and desecending order using bubble sort
#include<stdio.h>

int main(){
  int n;
  int arr[20];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  char val;
  printf("Enter a for ascending or d for descending order: ");
  scanf(" %c",&val);
  switch(val){
    case 'a':{
      for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
          if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
          }
        }
      }
      break;
    }
    case 'd':{
      for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
          if(arr[j] < arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
          }
        }
      }
      break;
    }
    default:{
      printf("Invalid input\n");
      break;
    }
  }
  for(int i = 0 ; i < n ; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}