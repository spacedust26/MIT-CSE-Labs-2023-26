// Write a C program that merges lines alternatively from 2 files and stores it in a resultant file

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2, *fptr3;
    char filename[50], c1, c2;
    //Open the first read file
    printf("Enter the first file path to read from: ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    if (!fptr1) {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    //Open the second read file
    printf("Enter the second file path to read from: ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "r");
    if (!fptr2) {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    //Open the write file
    printf("Enter the file path to be written to ");
    scanf("%s", filename);
    fptr3 = fopen(filename, "w+");
    //merge lines of the 2 reads files alternatively
    c1 = fgetc(fptr1);
    c2 = fgetc(fptr2);
    while (c1 != EOF || c2 != EOF) {
        while (c1 != '\n' && c1 != EOF) {
            fputc(c1, fptr3);
            c1 = fgetc(fptr1);
        }
        if (c1 == '\n')
            fputc(c1, fptr3);
        c1 = fgetc(fptr1);
        while (c2 != '\n' && c2 != EOF) {
            fputc(c2, fptr3);
            c2 = fgetc(fptr2);
        }
        if (c2 == '\n')
            fputc(c2, fptr3);
        c2 = fgetc(fptr2);
    }
    //Close all the files
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return 0;
}