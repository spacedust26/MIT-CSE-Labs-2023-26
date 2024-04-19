//To evaluate the given expressions
//i)(a + b) * c / d
//ii)((a + b) * c) / d   
//iii)a + (b * c) / d
//iv)(a + b) * (c / d)

#include<stdio.h>

int main(){
  int a = 30, b = 10, c = 5, d = 15;
  float q1 = (a + b) * c / d;
  float q2 = ((a + b) * c) / d;
  float q3 = a + (b * c) / d;
  float q4 = (a + b) * (c / d);
  printf("q1 = %.2f\nq2 = %.2f\nq3 = %.2f\nq4 = %.2f", q1, q2, q3, q4);
  return 0;
}