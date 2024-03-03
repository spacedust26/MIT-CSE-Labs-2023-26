//Top Down heap construction of a given array
//Input - an array h[1, n]
//Ouput - heapified array
//Time complexity - nlogn

#include<stdio.h>

//Global variable
int opcount = 0;

//Top Down approach
void topDown(int *h, int i){
  int p = i / 2;
  while(p > 0){
    opcount++;
    if(h[p] < h[i]){
      int temp = h[p];
      h[p] = h[i];
      h[i] = temp;
      i = p;
      p = i/2;
    }else return;
  }
  return;
}

//Main function
void main(){
  int n, h[100];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&h[i]);
    topDown(h,i);
  }
  printf("Heapified array: ");
  for(int i = 1 ; i <= n ; i++){
    printf("%d ",h[i]);
  }
  printf("\nOperation count: %d",opcount);
}