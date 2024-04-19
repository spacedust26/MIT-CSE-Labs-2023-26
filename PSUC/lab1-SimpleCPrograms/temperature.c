//Convert the temperature in fahrenheit to centigrade

#include<stdio.h>

int main(){
  float f,c;
  printf("Enter temperature in fahrenheit: ");
  scanf("%f",&f);
  c = (5 * (f- 32)) / 9;
  printf("Temperature in celsius: %.3f",c);
}