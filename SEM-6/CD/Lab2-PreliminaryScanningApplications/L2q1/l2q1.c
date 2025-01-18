// Write a C program that takes a file as input and replaces blank spaces and tabs by single space and writes the output to a file.

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr1, *fptr2;
    char filename[100], c;
	int n = 0, i;
	printf("Enter the filename to open: ");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");

	if (fptr1 == NULL) {
	printf("Cannot open file %s \n", filename);
	exit(0);
	}

	printf("Enter the filename to open for writing: ");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+");

    c = getc(fptr1);
    while(c != EOF){
        if(c == ' '){
            putc(c, fptr2);
            while(c == ' ') c = getc(fptr1);
        }
        putc(c, fptr2);
        c = getc(fptr1);
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}