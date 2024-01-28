// Write  a  program  to  implement brute-force  string  matching.Analyze  its  time efficiency.
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 //Brute force string match function
 int stringMatch(char text[], char pattern[]){
  int i,j;
  int opcount = 0;
  int m = strlen(text);
  int n = strlen(pattern);
  for(i=0; i<=(m-n) ; i++){
    for(j=0 ;j<n; j++){
      opcount++;
      if(text[i+j]!=pattern[j]){
        break;
      }
    }
    if(j == n){
      printf("\nOpcount = %d",opcount);
      return i;
    }
  }
  printf("\nOpcount = %d",opcount);
  return -1;
 }

 //Main function
 int main(){
  char text[40], pattern[40];
  printf("Enter text: ");
  scanf("%s",text);
  printf("Enter pattern: ");
  scanf("%s",pattern);
  int match = stringMatch(text, pattern);
  if(match!=-1){
    printf("\nString matching occured at %d index",match);
  }else{
    printf("\nNo string matching occured");
  }
  printf("\n");
  return 0;
 }