//Search the position of the number entered and delete it. Display the resultant array
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
  int k,pos=-1;
  printf("Enter number to be deleted from the array: ");
  scanf("%d",&k);
  for(int i = 0 ; i < n ; i++){
    if(arr[i] == k){
      pos = i;
      break;
    }
  }
  if(pos == -1) printf("Element not found in array\n");
  else{
    for(int i = pos ; i < n-1 ; i++){
      arr[i] = arr[i+1];
    }
    n--;
    for(int i = 0 ; i < n ; i++){
      printf("%d ", arr[i]);
    }
  }
  return 0;
}