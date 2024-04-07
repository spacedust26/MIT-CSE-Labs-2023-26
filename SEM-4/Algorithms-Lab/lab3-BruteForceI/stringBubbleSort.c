//Sort an array of strings using bubble sort
//Input - An array[0, n-1] of orderable elements
//Output - An arary[0, n-1] sorted in ascending order
//Time complexity - O(n^2)

#include<stdio.h>
#include<string.h>

//Bubble sort
void bubbleSort(char arr[][40], int n){
  int opcount = 0;
  char temp[40];
  for(int i = 0 ; i < n-1 ; i++){
    for(int j = 0 ; j < n-i-1 ; j++){
      opcount++;
      if(strcmp(arr[j+1] , arr[j]) < 0){
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j+1]);
        strcpy(arr[j+1], temp);
      }
    }
  }
  printf("\nOpcount = %d\n",opcount);
}

//Main function
int main(){
  int n;
  char arr[40][40];
  printf("Enter size: ");
  scanf("%d",&n);
  printf("Enter arary elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%s",arr[i]);
  }
  printf("\nAfter bubble sort: ");
  bubbleSort(arr,n);
  for(int i=0 ; i < n ; i++){
    printf("%s ",arr[i]);
  }
  return 0;
}