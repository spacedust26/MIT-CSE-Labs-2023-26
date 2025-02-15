#include<stdio.h>
#include<stdib.h>
#include<string.h>
#define TableLength 30

enum tokenType {EOFILE = -1, LESS_THAN, LESS_THAN_OR_EQUAL, GREATER_THAN, GREATER_THAN_OR_EQUAL, EQUAL, NOT_EQUAL};

struct token{
    char *lexeme;
    int index;
    unsigned int rowno, colno;
    enum token Type type;
};

struct ListElement{
    struct token tok;
    struct ListElement *next;
};

struct ListElement *TABLE[TableLength];

void initialize(){
    for(int i = 0; i < TableLength; i++) TABLE[i] = NULL;
}

void Display()