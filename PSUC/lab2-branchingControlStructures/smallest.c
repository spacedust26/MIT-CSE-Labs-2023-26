//find the smallest among the 3 numbers using conditional operator
#include<stdio.h>

int main(){
  int a, b, c;
  printf("Enter 3 numbers: ");
  scanf("%d %d %d",&a, &b, &c);
  int small = a < b ? ((a < c) ?  a : c) : ((b < c) ? b : c);
  printf("The smallest of the 3 numbers is %d",small);
  return 0;
}