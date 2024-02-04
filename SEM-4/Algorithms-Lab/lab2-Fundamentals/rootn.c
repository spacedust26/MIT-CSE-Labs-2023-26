//Computes the square root of a number n
//Input - positive integer n
//Output - square root of n
//Time complexity - O(sqrt(n))

#include<stdio.h>
#include<stdlib.h>

//Root of n 
int root(int n){
  int i;
  int opcount = 0;
  for(i = 1 ; i * i <= n ; i++){
    opcount++;
  }
  printf("Opcount = %d\n",opcount);
  return i-1;
}

//Main function
int main(){
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  printf("Square root is %d\n",root(n));
  return 0;
}