#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"la.h"

int main() {
    FILE *fin = fopen("sample.c", "r");
    if (!fin) {
        printf("Error! File cannot be opened!\n");
        return 0;
    }
    struct token tkn;
    int count = 1;
    while ((tkn = getNextToken(fin)).row != -1)
        printf( "%d. < %s , %d , %d, %s>\n", count++, tkn.type, tkn.row, tkn.col,tkn.lexeme);
    fclose(fin);
}