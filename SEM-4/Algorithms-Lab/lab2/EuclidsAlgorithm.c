//To find the GCD of two numbers using Euclid's algorithm
#include<stdio.h>
#include<stdlib.h>
int euclid(int m, int n){
  int opcount = 0;
  while(n!=0){
    int rd = m % n;
    opcount++;
    m = n;
    n = rd;
  }
  printf("Opcount = %d\n",opcount);
  return m;
}
int main(){
  int m,n;
  printf("Enter two numbers: ");
  scanf("%d %d",&m,&n);
    if(m==0 && n==0){
    printf("Invalid. Both the numbers cant be zero.");
  }
  else if(m<0 || n<0){
    printf("Invalid. The number(s) cannot be negative.");
  }
  else{
    printf("GCD using Euclids algorithm: %d",euclid(m,n));
  }
}