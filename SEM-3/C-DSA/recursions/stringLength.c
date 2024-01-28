//TO FIND LENGTH OF STRING USING RECURSION
#include<stdio.h>
#include<string.h>
int len(char str[],int i){
  if(str[i]=='\0')return i;
  else return len(str,i+1);
}
int main(){
  char str[20];
  printf("Enter string: ");
  scanf("%s",str);
  int i=0;
  printf("String length: %d",len(str,i));
}