//IMPLEMENT BINARY SEARCH 
#include<stdio.h>
int bin(int a[],int ele,int low,int high){
  if(low>high)return -1;
  int mid = (low+high)/2;
  if(ele<a[mid]) return bin(a,ele,low,mid-1);
  else if(ele==a[mid])return mid;
  else if(ele>a[mid]) return bin(a,ele,mid+1,high);
}
int main(){
  int a[10],ele,n;
  printf("Enter array limit: ");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Enter element to be searched: ");
  scanf("%d",&ele);
  int low=0;
  int high = n;
  int x=bin(a,ele,low,high);
  if(x !=-1)printf("Element found at %d position",x);
  else printf("Element not found");
}