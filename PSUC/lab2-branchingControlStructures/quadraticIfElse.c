//compute all the roots of a quadratic equation
#include<stdio.h>
#include<math.h>

int main(){
  float a, b, c;
  float discriminant = 0;
  printf("Enter values of a, b, c: ");
  scanf("%f %f %f",&a, &b, &c);
  discriminant = (b * b) - (4 * a * c);
  if(discriminant > 0){
    printf("Roots are real and distinct\n");
    float root1 = (-b + sqrt(discriminant)) / (2 * a);
    float root2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("Root 1 = %.2f\nRoot 2 = %.2f\n",root1,root2);
  }
  else if(discriminant == 0){
    printf("Roots are real and equal\n");
    float root = - b / (2 * a);
    printf("Root = %.2f",root);
  }else{
    printf("Roots are imaginary\n");
    float real = -b / (2 * a);
    float img = pow( fabs(discriminant),0.5 ) / (2 * a);
    printf("Root 1 = %.2f + i %.2f\n",real, img);
    printf("Root 2 = %.2f - i %.2f\n",real, img);
  }
  return 0;
}