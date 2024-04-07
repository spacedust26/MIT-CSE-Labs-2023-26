//program to find and delete minimum value in heap
#include<stdio.h>

//Bottom up approach
void bottomup(int *h, int l, int n){
  for(int i = n/2 ; i>=l ;i--){
    int k = i;
    int v = h[k];
    int heapify = 0;
    while(heapify == 0 && 2*k <=n){
      int j = 2 * k;
      if(j<n && h[j+1] > h[j]) j = j + 1;
      if(v >= h[j]) heapify = 1;
      else{
        h[k] = h[j];
        k = j;
      }
    }
    h[k] = v;
  }
}

//delete element
void delete(int *h, int n){
  int i;
  int min = 999;
  int min_index = -1;
  for(i = 1 ; i <= n ; i++){
    if(h[i] < min){
      min = h[i];
      min_index = i;
    }
  }
  if(min_index == -1){
    printf("\nNo such element found.");
    return;
  }else{
    int temp = h[min_index];
    h[min_index] = h[n];
    h[n] = temp;
  }
  bottomup(h,1,n-1);
}

//Main function
int main(){
  int n, h[50], ele;
  printf("Enter array size: ");
  scanf("%d",&n);
  printf("Enter heap elements: ");
  for(int i = 1 ; i <= n ; i++){
    scanf("%d",&h[i]);
  }
  delete(h,n);
  printf("\nAfter deletion: ");
  for(int i = 1 ; i < n ; i++){
    printf("%d ", h[i]);
  }
}