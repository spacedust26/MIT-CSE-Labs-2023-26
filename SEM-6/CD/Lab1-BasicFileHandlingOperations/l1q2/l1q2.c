// Write a C program to reverse the file contents and store in another file. Also display the size of file using file handling function.
#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fptr1, *fptr2;
  char filename[100], c;
  int n = 0;
  //Open the read file
  printf("Enter the file path to read from: ");
  scanf("%s", filename);
  fptr1 = fopen(filename, "r");
  if(fptr1 == NULL){
    printf("Cannot open the read file");
    exit(0);
  }
  //Open the write file
  printf("Enter the file path to write to: ");
  scanf("%s", filename);
  fptr2 = fopen(filename, "w+");
  if(fptr2 == NULL){
    printf("Cannot open the write file");
    exit(0);
  }
  //Copy contents
  c = fgetc(fptr1);
	while (c != EOF) {
		n++;
		c = fgetc(fptr1);
	}
	for(int i = n - 1; i >= 0; i--) {
		fseek(fptr1, i, SEEK_SET);
		c = fgetc(fptr1);
		fputc(c, fptr2);
	}
  printf("The contents of the file have been reversed and  copied.\n");
  //Close files
  fclose(fptr1);
  fclose(fptr2);
  return 0;
}