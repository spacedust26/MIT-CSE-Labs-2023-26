#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "la.h"

int main()
{
    FILE *fp = fopen("sample.c", "r");
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        exit(0);
    }
    struct token tkn;
    while (1)
    {
        tkn = getNextToken(fp);
        if (strcmp(tkn.type, "EOF") == 0)
            break;
        printf("<%s, %s, Row: %d, Col: %d>\n", tkn.lexeme, tkn.type, tkn.row, tkn.col);
    }
    fclose(fp);
    return 0;
}