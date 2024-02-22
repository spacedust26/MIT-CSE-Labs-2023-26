//To find the product of m and n using repeated addition
//Input - two integers m and n
//Ouput - product of m and n
//Time complexity - O(n)

#include<stdio.h>

//Finding product using repeated addition
int product(int m ,int n){
  int min = m < n ? m : n;
  m = m+n-min;
  int p = 0;
  for(int i = 0 ; i < min ; i++){
    p += m;
  }
  return p;
}

//Main function
int main(){
  int m, n;
  printf("Enter m and n: ");
  scanf("%d %d",&m, &n);
  int p = product(m,n);
  printf("Product: %d ",p);
}