//Write a program to find GCD using consecutive integer checking method
#include<stdio.h>
#include<stdlib.h>
int cim(int m, int n){
 int t = m < n ? m : n;
 int opcount = 0;
 while(t!=1){
  opcount++;
  if(m % t ==0){
    if(n % t ==0){
      printf("Opcount = %d",opcount);
      return t;
    }
  }
  t--;
 }
 opcount++;
 printf("Opcount = %d",opcount);
 return t;
}
int main(){
  int m,n;
  printf("Enter two numbers: ");
  scanf("%d %d",&m,&n);
  printf("\nGCD using Consecutive Integer Checking algorithm: %d",cim(m,n));
}