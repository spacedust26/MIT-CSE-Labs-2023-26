//program to find and delete a value in heap
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
void delete(int *h, int n, int ele){
  int i;
  for(i = 1 ; i <= n ; i++){
    if(h[i] == ele) break;
  }
  if(i > n){
    printf("\nNo such element found.");
    return;
  }else{
    int temp = h[i];
    h[i] = h[n];
    h[n] = temp;
  }
  if(i != n) bottomup(h,1,n-1);
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
  printf("Enter element to be deleted: ");
  scanf("%d",&ele);
  delete(h,n,ele);
  printf("\nAfter deletion: ");
  for(int i = 1 ; i < n ; i++){
    printf("%d ", h[i]);
  }
}