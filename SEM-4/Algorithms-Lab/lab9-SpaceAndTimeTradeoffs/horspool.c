//To perform string matching using horspool algorithm
//Input - text and pattern string
//Output - index of text match or -1 if no match
//Time complxity - O(mn) for worst case, O(n) for best case [n = text length]

#include<stdio.h>
#include<string.h>
//Global variables
int table[256];
int comparisons = 0;

//shift table function
void shifttable(char *pattern){
  for(int i = 0 ; i < 256 ; i++){
    table[i] = strlen(pattern);
  }
  for(int i = 0 ; i < strlen(pattern) - 1 ; i++){
    table[pattern[i]] = strlen(pattern) - 1 - i;
  }
}

//string match function 
int horspool(char *text, char *pattern){
  int plen = strlen(pattern);
  int tlen = strlen(text);
  int i = plen - 1;
  while(i < tlen){
    int k = 0;
    while((k < plen) && (text[i-k] == pattern[plen-1-k])){
      comparisons++;
      k++;
    }
    if(k == plen) return i - plen + 1;
    else{
      comparisons++;
      i += table[text[i]];
    }
  }
  return -1;
}

//Main function
int main(){
  char text[30], pattern[30];
  printf("Enter text: ");
  scanf("%s",text);
  printf("Enter pattern: ");
  scanf("%s",pattern);
  shifttable(pattern);
  int hp = horspool(text, pattern);
  if(hp == -1) printf("No string matching");
  else printf("String matching in text at index %d.",hp);
  printf("\nTotal key comparisons: %d",comparisons);
}