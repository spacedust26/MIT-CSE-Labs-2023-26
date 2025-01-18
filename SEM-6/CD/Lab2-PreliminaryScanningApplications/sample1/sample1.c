// Program to remove single and multiline comments from a given 'C' file

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr1, *fptr2;
    char filename[100], c1, c2;
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

    c1 = getc(fptr1);
    while(c1 != EOF){
        if(c1 == ' '){
            putc(c1, fptr2);
            while(c1 == ' ') c1 = getc(fptr1);
        }
        if(c1 == '/'){
            c2 = getc(fptr1);
            if(c2 == '/'){
                while(c1 != '\n') c1 = getc(fptr1);
            }
            else if(c2 == '*'){
                do{
                    while(c1 != '*') c1 = getc(fptr1);
                    c1 = getc(fptr1);
                }while(c1 != '/');
            }
            else{
                putc(c1, fptr2);
                putc(c2, fptr2);
            }
        }
        else putc(c1, fptr2);
        c1 = getc(fptr1);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}