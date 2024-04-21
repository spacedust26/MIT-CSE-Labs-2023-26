//check whether the string is palindrome or not
#include<stdio.h>
#include<string.h>

int main(){
  char str[30];
  int count = 1;
  printf("Enter string: ");
  gets(str);
  int n = strlen(str);
  for(int i = 0 , j = n - 1; i < j ; i++, j--){
    if(str[i] != str[j]){
      count = 0;
      break;
    }
  }
  if(count == 0)printf("Not palindrome");
  else printf("Palindrome");
  return 0;
}