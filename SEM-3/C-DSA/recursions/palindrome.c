//TO FIND IF A STRING IS PALINDROMIC USING RECURSIONS
#include<stdio.h>
#include<string.h>
int palin(char str[],int low,int high){
  if(low>=high)return 1;
  if(str[low]==str[high]) return palin(str,low+1,high-1);
  else return 0;
}
int main(){
  char str[20];
  printf("Enter string: ");
  scanf("%s",str);
  int low =0;
  int high = strlen(str)-1;
  if(palin(str,low,high))printf("Palindrome");
  else printf("Not palindrome");
}