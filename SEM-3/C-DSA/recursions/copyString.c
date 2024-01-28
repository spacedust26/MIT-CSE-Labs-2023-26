//TO COPY ONE STRING TO ANOTHER USING RECURSION
#include<stdio.h>
void copy(char a[],char b[],int i){
  b[i]=a[i];
  if(a[i]=='\0')return;
  else return copy(a,b,i+1);
}
int main(){
  char a[20],b[20];
  printf("Enter string: ");
  scanf("%s",a);
  int i=0;
  copy(a,b,i);
  printf("Copied string: %s",b);
}