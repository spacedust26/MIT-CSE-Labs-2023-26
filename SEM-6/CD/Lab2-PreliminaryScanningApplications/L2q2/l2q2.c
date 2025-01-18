// Write a C program to discard preprocessor directives from the given input 'C file

#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fptr1, *fptr2;
    char filename[100], c, c2;
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
        // check for # within a print statement
        if(c == '"'){
            fputc(c, fptr2);
            c = fgetc(fptr1);
            while(c != '"'){
                fputc(c, fptr2);
                c = fgetc(fptr1);
            }
            fputc(c,fptr2);
        }
        // check for # in comments
        else if (c == '/'){
            c2 = fgetc(fptr1);
            if (c2 == '/'){
                fputc(c2, fptr2);
                while (c != '\n'){
                    fputc(c, fptr2);
                    c = fgetc(fptr1);
                }
            }
            else if (c2 == '*'){
                fputc(c, fptr2);
                fputc(c2, fptr2);
                c = fgetc(fptr1);
                do{
                    while (c != '*'){
                        fputc(c, fptr2);
                        c = fgetc(fptr1);
                    }
                    fputc(c, fptr2);
                    c = fgetc(fptr1);
                } while (c != '/');
                fputc(c, fptr2);
            }
        }
        // check for # in pre processor directives
        else if (c == '#'){
            while (c != '\n'){
                c = fgetc(fptr1);
            }
        }
        else fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}