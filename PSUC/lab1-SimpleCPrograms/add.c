//C program to add 2 integers aa and b read from the keyboard. Display the sum in third varaible sum
#include<stdio.h>

int main(){
  int a, b, sum=0;
  printf("Enter a and b: ");
  scanf("%d %d",&a,&b);
  sum = a + b;
  printf("Sum = %d", sum);
  return 0;
}