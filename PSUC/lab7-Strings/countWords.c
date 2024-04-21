//program to count the number of words in a sentence
#include<stdio.h>

int main(){
  char *s;
  int count = 1;
  printf("Enter sentence: ");
  scanf("%[^\n]",s);
  int i = 0;
  while(s[i] != '\0'){
    if(s[i] == ' ')count++;
    i++;
  }
  printf("The total words in the sentence are : %d", count);
}