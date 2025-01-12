// Write a C program to count the number of lines and characters in a file

#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fptr;
  char filename[100], c;
  int lines=0, characters=0, words=0;
  //Open the read file
  printf("Enter the file path to read from: ");
  scanf("%s", filename);
  fptr = fopen(filename, "r");
  if(fptr == NULL){
    printf("Cannot open the read file");
    exit(0);
  }
  //Count characters, lines, words
  while((c = fgetc(fptr)) != EOF){
    characters++;
    if(c == '\n') lines++;
    if(c == ' ' || c == '\t' || c == '\n') words++;
  }
  if(characters > 0 && c != '\n'){
    words++;
    lines++;
  }
  printf("Total characters = %d\n", characters);
  printf("Total words      = %d\n", words);
  printf("Total lines      = %d\n", lines);

  //Close files
  fclose(fptr);
  return 0;
}