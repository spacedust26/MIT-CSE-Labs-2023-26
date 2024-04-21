//input string and toggle case every character
#include<stdio.h>

int main(){
  char s[20];
  printf("Enter sentence: ");
  gets(s);
  for(int i = 0 ; s[i] != '\0' ; i++){
    if(s[i] >= 'A' && s[i]<='Z'){
      s[i] = s[i] + 32;
    }
    else s[i] = s[i] - 32;
  }
  puts(s);
}