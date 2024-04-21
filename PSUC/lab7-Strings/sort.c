//Arrange n names in alphabetical order
#include<stdio.h>
#include<string.h>

int main(){
  char list[20][20],n;
  char temp[20];
  printf("Enter the number of names: ");
  scanf("%d",&n);
  printf("Enter the names: ");
  fflush(stdin);
  for(int i = 0; i < n ; i++){
    gets(list[i]);
  }
  for(int i = 0; i < n-1 ; i++){
    for(int j = 0; j < n-i-1 ; j++){
      if(strcmp(list[j], list[j+1]) > 0){
        strcpy(temp,list[j]);
        strcpy(list[j],list[j+1]);
        strcpy(list[j+1],temp);
      }
    }
  }
  printf("Names in sorted order: ");
  for(int i = 0 ; i < n ; i++){
    puts(list[i]);
  }
  return 0;
}