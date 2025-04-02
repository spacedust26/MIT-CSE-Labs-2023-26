// Write a C program to reverse the file contents and store in another file. Also display the size of file using file handling function

#include<stdio.h>
#include<stdlib.h>

int main(){
 FILE *fp1, *fp2;
 char filename[100], c;

 //Open the read file
 printf("Enter the file path to read from: ");
 scanf("%s", filename);
 fp1 = fopen(filename, "r");
 if(fp1 == NULL){
 printf("Cannot open the read file");
 exit(0);
 }

 //Open the write file
 printf("Enter the file path to write to: ");
 scanf("%s", filename);
 fp2 = fopen(filename, "w+");
 if(fp2 == NULL){
 printf("Cannot open the write file");
 exit(0);
 }

 // Display file size
 fseek(fp1, 0, SEEK_END);
 long file_size = ftell(fp1);
 printf("The size of the file is %ld.\n", file_size);

 // Reverse the content
 for(int i = file_size-1; i>=0 ;i--){
 fseek(fp1, i, SEEK_SET);
 c = fgetc(fp1);
 fputc(c, fp2);
 }
 printf("Contents of the file have been reversed and stored in %s.", filename);

 // Close the files
 fclose(fp1);
 fclose(fp2);
 return 0;
}