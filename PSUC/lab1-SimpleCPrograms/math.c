//Prgram to calculate sum, difference, product , quotient of 2 numbers
#include<stdio.h>

int main(){
  float a, b, sum=0;
  printf("Enter a and b: ");
  scanf("%f %f",&a,&b);
  printf("Sum = %.2f\n", a + b);
  printf("Difference = %.2f\n", a - b);
  printf("Product = %.2f\n", a * b);
  if (b == 0) printf("Divide by zero error");
  else printf("Quotient = %.2f\n", a / b);
  return 0;
}