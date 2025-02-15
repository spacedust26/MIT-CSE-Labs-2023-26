// 1. Using getNextToken( ) implemented in Lab No 3, design a Lexical Analyser to implement the
// following symbol tables.
// a. local symbol table
// b. global symbol table

#include "la.h"

struct node {
    char lexeme[20];
    struct node* next;
};

int cnt=1;
struct entry {
    int index;
    char lexeme[20];
    char type[10];  
    char dtype[10];
    int size;
};

const char *Datatypes[] = {"int", "char", "float"};
struct entry symbolTable[100];
int entryCount = 0;

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return (hash % 100);
}

struct node* HashMap[100] = {NULL};

void insert(char* str) {
    int hashVal = hash(str);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->lexeme, str);
    temp->next = HashMap[hashVal];
    HashMap[hashVal] = temp;
}

int search(char* str) {
    int hashVal = hash(str);
    struct node* temp = HashMap[hashVal];
    while (temp != NULL) {
        if (strcmp(temp->lexeme, str) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int retSize(const char* dtype) {
    if (strcmp(dtype, "int") == 0) return 4;
    if (strcmp(dtype, "char") == 0) return 1;
    if (strcmp(dtype, "float") == 0) return 4;
    if (strcmp(dtype, "FUNC") == 0) return -1;
    return 0;
}

int isDtype(const char* str) {
    for (int i = 0; i < sizeof(Datatypes) / sizeof(char*); i++) {
        if (strcmp(str, Datatypes[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE* fin = fopen("sampleread.c", "r");
    if (!fin) {
        printf("Error! File cannot be opened!\n");
        return 0;
    }

    struct token tkn;
    char currentDtype[10] = "Void";
    int i = 1;

    while ((tkn = getNextToken(fin)).row != -1) {
        printf("%d. <%s, %d, %d>\n", cnt++, tkn.type, tkn.row, tkn.col);

        struct entry tuple;
        tuple.index = i++;
        strcpy(tuple.lexeme, tkn.lexeme);
        strcpy(tuple.type, tkn.type);

        if (strcmp(tkn.type, "Keyword") == 0 && isDtype(tkn.lexeme)) {
            strcpy(currentDtype, tkn.lexeme);  
            strcpy(tuple.dtype, "Void"); 
            tuple.size = 0;
        } else if (strcmp(tkn.type, "Identifier") == 0) {
            strcpy(tuple.dtype, currentDtype); 
            tuple.size = retSize(currentDtype);
        } else {
            strcpy(tuple.dtype, "N/A");
            tuple.size = 0; 
        }

        if (search(tuple.lexeme) == 0) {
            symbolTable[entryCount++] = tuple;
            insert(tuple.lexeme);
        }

        if (strcmp(tkn.lexeme, ";") == 0) {
            strcpy(currentDtype, "Void");
        }
    }

    printf("\n\n\t\t\tSYMBOL TABLE\n\n");
    printf("Index, Lexeme, Type, Dtype, Size\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d, %s, %s, %s, %d\n",
               symbolTable[i].index,
               symbolTable[i].lexeme,
               symbolTable[i].type,
               symbolTable[i].dtype,
               symbolTable[i].size);
    }

    fclose(fin);
    return 0;
}