//to find the maximum number in the input integer array using pointers
#include<stdio.h>

int main(){
  int n, arr[20];
  printf("Enter array size: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d", &arr[i]);
  }
  int *f = arr;
  int *l = arr;
  for(int i = 1; i<n ; i++){
    if(*(l+i) > *f){
      f = l + i;
    }
  }
  printf("Maximum element: %d", *f);
}