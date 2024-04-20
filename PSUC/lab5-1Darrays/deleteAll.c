//delete all occurances of the element
#include<stdio.h>

int main(){
  int n, k, pos;
  int arr[20];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter element to be deleted: ");
  scanf("%d",&k);
  for(int i = 0 ; i <  n ; i++){
    if(arr[i] == k){
      pos = i;
      for(int j = pos + 1; j < n; j++){
        arr[j - 1] = arr[j];
      }
      n--;
      i--;
    }
  }
  for(int i = 0 ; i < n ; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}