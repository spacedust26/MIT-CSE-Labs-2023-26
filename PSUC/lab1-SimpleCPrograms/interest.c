//To compute simple interest and compound interest
#include<stdio.h>
#include<math.h>

int main(){
  float p,t,r,si= 0,ci=0;
  printf("Enter value of p, t and r: ");
  scanf("%f %f %f",&p,&t,&r);
  si = (p * t * r) / 100;
  ci = p * pow(1 + (r/100), t) - p;
  printf("Simple interest: %.2f\nCompound interest: %.2f\n",si,ci);
  return 0;
}