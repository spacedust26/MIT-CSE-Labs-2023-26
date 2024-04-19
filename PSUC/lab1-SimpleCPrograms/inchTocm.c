//Program to convert length in inches to cm
#include<stdio.h>

int main(){
  float n;
  printf("Enter number in inches: ");
  scanf("%f",&n);
  printf("Result in cm: %.2f", n * 2.54);
  return 0;
}