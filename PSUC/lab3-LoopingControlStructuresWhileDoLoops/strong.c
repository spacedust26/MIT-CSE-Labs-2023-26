//check if a number is strong or not
#include<stdio.h>

int main(){
  int num;
  printf("Enter number: ");
  scanf("%d",&num);
  int n = num, rd, rem, sum=0;
  while(n != 0){
    rd = n % 10;
    rem = 1;
    while(rd > 0){
      rem *= rd;
      rd--;
    }
    sum += rem;
    n /= 10;
  }
  if(sum == num)printf("Strong number");
  else printf("Not a strong number");
  return 0;
}