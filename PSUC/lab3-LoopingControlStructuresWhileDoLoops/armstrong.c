//Check for armstrong number (sum of the cubes of all digits of an inputted number equals the number itself) ex: 153

#include<stdio.h>

int main(){
  int num;
  printf("Enter number: ");
  scanf("%d",&num);
  int n = num;
  int sum = 0;
  int rd;
  while(n != 0){
    rd = n % 10;
    sum += (rd * rd * rd);
    n /= 10;
  }
  if(sum == num)printf("Armstrong number");
  else printf("Not an armstrong number");
  return 0;
}