//find the sum of 100 natural numbers
#include<stdio.h>

int main(){
  int sum = 0;
  int i = 1;
  while(i < 101){
    sum += i;
    i++;
  }
  printf("Sum of 100 natural numbers using while loop = %d\n", sum);

  sum = 0;
  i = 1;
  do{
    sum += i;
    i++;
  }while(i < 101);
   printf("Sum of 100 natural numbers using do while loop = %d", sum);
   return 0;
}