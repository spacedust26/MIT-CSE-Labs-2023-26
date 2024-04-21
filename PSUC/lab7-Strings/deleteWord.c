//delete a word from the given sentence
#include<stdio.h>
#include<string.h>

int main(){
  char str[30], del[10];
  int pos = -1, i, j;
  printf("Enter sentence: ");
  puts(str);
  printf("Enter word to be deleted: ");
  puts(del);
  int m = strlen(str);
  int n = strlen(del);
  for(i = 0 ; i <= m-n ; i++){
    for(j = 0; j < n ; j++){
      if(str[i + j] != del[j]) break;
    }
    if(j == n){
      pos = i;
      break;
    }
  }
  if(pos == -1)printf("Word to be deleted not found");
  else{
    int last = pos + n - 1;
    for(i = pos ; i < n ; i++){
      str[i] = str[last++];
    }
    str[i] = '\0';
    puts(str);
  }
  return 0;
}
