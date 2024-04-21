//to find the factorial of a given number and compute NCR
#include<stdio.h>

int fact(int num){
  int ans = 1;
  while(num != 0){
    ans *= num;
    num--;
  }
  return ans;
}

int main(){
  int num, n, r;
  printf("Enter number: ");
  scanf("%d",&num);
  printf("Factorail = %d", fact(num));
  printf("\nEnter N and R values to compute NCR: ");
  scanf("%d %d", &n, &r);
  int res = fact(n) / (fact(r) * fact(n-r));
  printf("NCR = %d", res);
  return 0;
}