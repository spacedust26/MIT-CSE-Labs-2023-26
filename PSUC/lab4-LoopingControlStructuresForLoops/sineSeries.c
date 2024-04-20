//To evaluate the sine series sin(x)= x- x3/3! + x5/5!–x7/7!+ ......... to n terms

#include<stdio.h>
#include<math.h>
#define pi 3.141592

int main(){
  int n;
  float x, term , sum;
  printf("Enter limit: ");
  scanf("%d",&n);
  printf("Enter value of x in pi: ");
  scanf("%f",&x);
  x = x * (pi/180);
  term = x, sum = x;
  printf("sin(%f) = %f\n", x, sin(x));
  for(int i = 1; i <=n ; i++){
    term *= (-1 * x * x) / ((2*i)*(2*i + 1));
    sum += term;
  }
  printf("From sine series = %f", sum);
  return 0;
}
