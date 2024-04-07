//Progarm to checek if an array is heap or not

#include<stdio.h>
#include<stdbool.h>

//check if the array is a heap
bool heapcheck(int *arr, int n){
  for(int i = n/2 ; i>=1 ; i--){
    if(2*i <= n && arr[i] < arr[2*i]) return false;
    if(2*i+1<=n && arr[i] < arr[2*i+1])return false;
  }
  return true;
}

//Main funtion
int main(){
  int n, arr[50];
  printf("Enter array size: ");
  scanf("%d",&n);
  printf("Enter heap elements: ");
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&arr[i]);
  }
  if(heapcheck(arr,n))printf("Heap.");
  else printf("Not heap.");
}