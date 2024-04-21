//to check if a given string is a palindrome or not

#include<stdio.h>
#include<string.h>

int isPalin(char str[]){
  int n = strlen(str);
  for(int i = 0, j = n-1; i < j ; i++, j-- ){
    if(str[i] != str[j]) return 0;
  }
  return 1;
}

int main(){
  char str[20];
  printf("Enter string: ");
  gets(str);
  if(isPalin(str))printf("Palindrome");
  else printf("Not a palindrome");
  return 0;
}