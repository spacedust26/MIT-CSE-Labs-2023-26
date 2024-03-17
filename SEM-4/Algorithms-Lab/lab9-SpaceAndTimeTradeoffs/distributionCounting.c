//To sort an array using distribution counting
//Input - an array A[0,...n-1] of integers between l and u
//Output - sorted array in non decreasing order
//Time complexity - O(n)

#include<stdio.h>

//Distribution counting
void distributionCount(int *arr, int n, int l ,int u){
  int dtable[30];
  //Initialise frequency
  for(int i = 0; i <= u - l ; i++){
    dtable[i] = 0;
  }
  //Compute frequency
  for(int i = 0 ; i < n ; i++){
    dtable[arr[i]-l]++;
  }
  //Reuse for distribution
  for(int i = 1 ; i <= u-1 ; i++){
    dtable[i] += dtable[i-1];
  }
  int newarr[30];
  for(int i = n-1 ; i >=0 ; i--){
    newarr[dtable[arr[i] - l] - 1] = arr[i];
    dtable[arr[i] - l]--;
  }
  for(int i = 0 ; i < n ; i++){
    arr[i] = newarr[i];
  }
}

//Main function
int main(){
  int n, arr[30], l, u;
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter lower bound: ");
  scanf("%d",&l);
  printf("Enter upper bound: ");
  scanf("%d",&u);
  printf("Enter array elements: ");
  for(int i = 0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  distributionCount(arr, n, l, u);
  for(int i = 0 ; i < n ; i++){
    printf("%d ",arr[i]);
  }
}