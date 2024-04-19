//to chcek if a given number is odd or even
#include<stdio.h>

int main(){
  int n;
  printf("Enter a number: ");
  scanf("%d",&n);
  if(n % 2 == 0) printf("Even");
  else printf("odd");
  return 0;
}