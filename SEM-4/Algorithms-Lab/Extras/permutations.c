//To find permutations 
//Input - array size and array elements
//Output - Possible permutations
//Time complexity - O(n!)

#include<stdio.h>
//swap function
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

//Permutations function
void permute(int arr[], int start, int end){
  if(start == end){
    for(int i = 0 ; i <= end ; i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
  }else{
    for(int i = start; i<=end; i++){
      swap(&arr[start], &arr[i]);
      permute(arr, start+1, end);
      swap(&arr[start], &arr[i]);
    }
  }  
}

//Main function
int main(){
  int n, arr[40];
  printf("Enter array size: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("Permutations: \n");
  permute(arr, 0 , n-1);
}