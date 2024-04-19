//reverse a number and check if it is a palindrome
#include<stdio.h>

int main(){
  int num;
  printf("Enter number: ");
  scanf("%d",&num);
  int n = num;
  int rev = 0;
  while(n != 0){
    rev = (rev * 10) + n % 10;
    n /= 10;
  }
  printf("Reversed number = %d\n", rev);
  if(rev == num) printf("Palindrome");
  else printf("Not a palindrome");
  return 0;
}