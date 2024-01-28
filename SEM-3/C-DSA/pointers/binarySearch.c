//TO IMPLEMENT BINARY SEARCH USING POINTERS
#include<stdio.h>
int bin(int a[],int k,int n){
  int *low=a;
  int *high=a+n-1;
  while(low<=high){
    int *mid = low + (high-low)/2;
    if(k<*mid) high=mid-1;
    else if(k==*mid) return mid-a;
    else if(k>*mid) low = mid+1;
  }
  return -1;
}
int main(){
  int n,a[10],k;
  printf("Enter array size: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Enter element to be searched: ");
  scanf("%d",&k);
  int x = bin(a,k,n);
  if(x!=-1)printf("Element found at %d",x);
  else printf("Element not found");
}