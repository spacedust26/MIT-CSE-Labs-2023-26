//to find gcd of 2 numbers 
#include<stdio.h>

int gcd(int m, int n){
  while(n != 0){
    int rd = m % n;
    m = n;
    n = rd;
  }
  return m;
}

int main(){
  int m,n;
  printf("Enter 2 numbers: ");
  scanf("%d %d",&m, &n);
  printf("GCD: %d", gcd(m,n));
  return 0;
}