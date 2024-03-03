//Bottom up heap construction for a given array
//Input - array h[1, .. n] of orderable elements
//Output - heapified array 
//Time analysis - O(n)

#include<stdio.h>

//Bottom Up approach
void bottomUp(int *h, int n){
  for(int i = n/2 ; i >= 1 ; i--){
    int k = i;
    int v = h[k];
    int heapify = 0;
    while(heapify == 0 && 2*k <= n){
      int j = 2*k;
      if(j<n && h[j]<h[j+1]) j = j + 1; //get the larger child node
      if(v >= h[j]) heapify = 1;
      else{
        h[k] = h[j];
        k = j;
      }
    }
    h[k] = v;
  }
  return;
}

//Main fucntion
int main(){
  int n, h[100];
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i = 1 ; i <= n ; i++){ //index starts from 1
    scanf("%d",&h[i]);
  }
  bottomUp(h,n);
  printf("Heapified array: ");
  for(int i = 1 ; i <= n ; i++){
    printf("%d ",h[i]);
  }
}