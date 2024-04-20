//Find the generic root of a number. (sum of the digits of the number until a single digit is obtained)
#include<stdio.h>

int main(){
  int num;
  printf("Enter value of n: ");
  scanf("%d",&num);
  while(num > 9){
    int n = num;
    int sum = 0;
    while(n != 0){
      sum += n % 10;
      n /= 10;
    }
    num = sum;
  }
  printf("Generic root = %d", num);
  return 0;
}