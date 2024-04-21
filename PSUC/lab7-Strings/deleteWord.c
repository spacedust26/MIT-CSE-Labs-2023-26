//delete a word from the given sentence
#include<stdio.h>
#include<string.h>

int main(){
  char str[30], del[10];
  int pos = -1, i, j;
  printf("Enter sentence: ");
  fgets(str, sizeof(str), stdin); // Input sentence using fgets
  printf("Enter word to be deleted: ");
  scanf("%s", del); // Input word to be deleted
  
  int m = strlen(str);
  int n = strlen(del);
  
  for(i = 0; i <= m - n; i++){
    for(j = 0; j < n; j++){
      if(str[i + j] != del[j]) break;
    }
    if(j == n){
      pos = i;
      break;
    }
  }
  
  if(pos == -1)
    printf("Word to be deleted not found\n");
  else{
    int last = pos + n;
    for(i = pos; i < m - n + 1; i++){
      str[i] = str[last++];
    }
    str[i] = '\0';
    printf("Resulting sentence: %s\n", str);
  }
  return 0;
}
