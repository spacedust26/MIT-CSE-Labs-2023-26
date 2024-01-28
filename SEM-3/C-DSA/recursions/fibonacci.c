//TO FIND THE FIBONACCI NUMBER IN THE SEQUENCE 0112358...
#include<stdio.h>
int fib(int n){
  if(n==1 || n==0)return n;
  else return fib(n-1)+fib(n-2);
}
int main(){
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  printf("Fibonacci number: %d",fib(n));
}