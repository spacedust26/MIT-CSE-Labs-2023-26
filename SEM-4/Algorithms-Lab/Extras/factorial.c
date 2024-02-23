//To find the factorial of an integer
//Input - a positive integer n
//Output - factorial of n
//Time complexity - O(n)

#include<stdio.h>

//Factorial function
int fact(int n){
  if(n == 0) return 1;
  else return n * fact(n-1);
}

//Main function
int main(){
  int n;
  printf("Enter number: ");
  scanf("%d",&n);
  printf("Factorial: %d",fact(n));
}
