//insert an element into a 1D array by getting and element and the position from the user
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
  int k, pos;
  printf("Enter element and position to be inserted: ");
  scanf("%d %d",&k, &pos);
  if(pos < 0 || pos > n) printf("Invalid position\n");
  else {
    n = n + 1;
    for(int i = n-1 ; i > pos ; i--){
      arr[i] = arr[i-1];
    }
    arr[pos] = k;
    for(int i = 0 ; i < n ; i++){
      printf("%d ",arr[i]);
    }
  }
  return 0;
}