//To find the mode of a presorted array
//Input - presorted array
//Output - mode of the array
//Time complexity - O(n)

#include<stdio.h>

//mode function
int mode(int arr[20], int n){
  int mode = arr[0];
  int maxcount = 0;
  int current = arr[0];
  int count = 1;
  for(int i = 1 ; i < n ; i++){
    if(arr[i] == current) count++;
    else{
      current = arr[i];
      count = 1;
    }
    if(count > maxcount){
      maxcount = count;
      mode = current;
    }
  }
  return mode;
}

//Main function
int main(){
  int n, arr[20];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter sorted array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  printf("Mode element = %d",mode(arr,n));
  return 0;
}