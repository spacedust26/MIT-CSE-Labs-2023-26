//Brute force string matching algorithm
//Input - Text string and pattern string 
//Output - Index of the text string that matches with the pattern string
//Time complexity - O(mn) [for worst case]

#include<stdio.h>
#include<string.h>

//Brute force string matching
int stringMatch(char text[], char pattern[]){
  int m = strlen(text);
  int n = strlen(pattern);
  int opcount = 0, i, j;
  for(i = 0; i <= (m-n) ; i++){
    for(j=0 ; j<n ;j++){
      opcount++;
      if(text[i+j] != pattern[j]) break;
    }
    if(j == n) {
      printf("Opcount = %d",opcount);
      return i;
    }
  }
  printf("\nOpcount = %d\n",opcount);
  return -1;
}

//Main function
int main(){
  char text[40], pattern[40];
  printf("Enter text: ");
  scanf("%s",&text);
  printf("Enter pattern: ");
  scanf("%s",&pattern);
  int index = stringMatch(text, pattern);
  if(index == -1) printf("\nPattern not found");
  else printf("\nPattern found at index %d",index);
  return 0;
}