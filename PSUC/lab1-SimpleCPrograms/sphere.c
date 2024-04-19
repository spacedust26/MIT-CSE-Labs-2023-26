//input radius to find the volume and surface arae of the sphere
#include<stdio.h>
#define pi 3.14

int main(){
  float r, volume=0, surface_area = 0;
  printf("Enter radius: ");
  scanf("%f",&r);
  volume = (4 * pi * r * r * r) / 3;
  surface_area = (4 * pi * r *r);
  printf("Volume = %.3f\nSurface area = %.3f\n",volume, surface_area);
  return 0;
}