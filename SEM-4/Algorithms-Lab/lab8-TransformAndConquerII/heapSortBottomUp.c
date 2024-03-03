//To sort a list of integers using heap sort with bottom up max heap construction
//Input - an array h[1,..n] of orderable elements
//Ouput - sorted array
//Time complexity - n logn

#include<stdio.h>

//Global variable
int opcount = 0;

//Bottom Up approach
void bottomUp(int *h,int l, int n){
  for(int i = n/2 ; i >= l ; i--){
    int k = i;
    int v = h[k];
    int heapify = 0;
    while(heapify == 0 && 2*k <= n){
      opcount++;
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

//Heap sort 
void heapSort(int *h, int n){
  int k = 0;
  for(int i = 1 ; i <= n ; i++){
    bottomUp(h, 1, n-k);
    int temp = h[1];
    h[1] = h[n-k];
    h[n-k] = temp;
    k++; 
  }
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
  heapSort(h,n);
  printf("\nHeap sort array: ");
  for(int i = 1 ; i <= n ; i++){
    printf("%d ",h[i]);
  }
  printf("\nOperation count = %d",opcount);
}