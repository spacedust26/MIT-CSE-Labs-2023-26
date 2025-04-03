// Write a program in 'C' to identify the arithmetic and relational operators from the given input 'C' file

#include<stdio.h>
#include<stdlib.h>

int main(){
  char c1, c2;
  int i = 0;

  // Open file to read from
  FILE *fp = fopen("input.c", "r");
  if(fp == NULL){
    printf("Cannot open the file");
    exit(0);
  }

  // Identify relational and arithmetic operators
  while((c1 = fgetc(fp)) != EOF){
    if(c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/' || c1 == '%'){
      printf("Arithmetic Operator %c\n", c1);
    }
    else if(c1 == '=' || c1 =='!' || c1 == '<' || c1 == '>'){
      c2 = fgetc(fp);
      if(c2 == '=') printf("Relational Operator %c%c\n",c1, c2);
      else printf("Relational Operator %c\n", c1);
    }
  }

  // Close file
  fclose(fp);
  return 0;
}

