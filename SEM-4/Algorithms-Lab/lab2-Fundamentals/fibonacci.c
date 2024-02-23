//Compute the nth fibonacci number recursively
// 0 1 1 2 3 5 8 13(sequence)
// 0 1 2 3 4 5 6 7 (index)
//Input - Position of the fibonacci number to be found - n
//Output - nth fibonacci number
//Time complexity - O(2^n)

#include<stdio.h>

//Fibonacci recursive function
int fib(int n){
  if(n == 0 || n == 1) return n;
  else return fib(n-1) + fib(n-2);
}

//Main function
int main(){
  int n;
  printf("Enter n(index): ");
  scanf("%d",&n);
  printf("nth fibonacci number: %d ",fib(n));
}