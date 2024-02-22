//Euclids algorithm gcd(m,n)
//Input - two non negative not-both-zero integers
//Output - greatest common divisor of m and n
//Time complexity - O(log n)

#include<stdio.h>

//Approach 1 - using while loop
int euclid1(int m , int n){
  int opcount = 0;
  while(n != 0){
    int r = m % n;
    opcount++;
    m = n;
    n = r;
  }
  printf("Opcount = %d\n",opcount);
  return m;
}

//Approach 2 - using recursion
int euclid2(int m, int n){
  if(n == 0) return m;
  else return euclid2(n , m % n);
}

//Main function
int main(){
  int m,n;
  printf("Enter m and n: ");
  scanf("%d %d",&m,&n);
  printf("GCD using Euclids algorithm approach 1 (while loop): %d \n",euclid1(m,n));
  printf("GCD using Euclids algorithm approach 2 (recursion): %d \n",euclid2(m,n));
  return 0;
}