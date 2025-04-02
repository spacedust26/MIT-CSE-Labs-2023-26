// Write a C program, that takes a C program as input , recognizes all keywords and prints them in uppercase

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char keys[32][10] = {"auto","break","case","char","continue","do","default","const","double","else","enum","extern","for","if","goto","float","int","long","register","return","signed","static","sizeof","short","struct","switch","typedef","union","void","while","volatile","unsigned"};
    char buff[50], filename[50], c;
    FILE *fptr1, *fptr2;
    printf("Enter the file path to be read from: ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    if (!fptr1){
        printf("File does not exist.\n");
        exit(0);
    }
    printf("Enter the file path to write to: ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "w+");
    
    c = fgetc(fptr1);
    int i = 0, k = 0;
    while (c != EOF){
        if (isalpha(c)){
            buff[i++] = c;
            c = fgetc(fptr1);
            while (isalpha(c)){
                buff[i++] = c;
                c = fgetc(fptr1);
            }
            buff[i] = '\0';
            for (int j = 0; j < 32; j++){
                if (strcmp(buff, keys[j]) == 0) {
                    while (buff[k]) fputc(toupper(buff[k++]), fptr2);
                    fputc('\n', fptr2);
                    break;
                }
            }
        }
        i = 0;
        k = 0;
        memset(buff, 0, 50);
        c = fgetc(fptr1);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
