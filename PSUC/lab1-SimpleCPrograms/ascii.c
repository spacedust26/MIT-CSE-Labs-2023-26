//Program to print ASCII value of a character
#include<stdio.h>

int main(){
  char c;
  printf("Enter character: ");
  scanf("%c",&c);
  printf("ASCII value of %c is %d.",c,c);
  return 0;
}