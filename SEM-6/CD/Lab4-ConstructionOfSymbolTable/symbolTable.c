// 1. Using getNextToken( ) implemented in Lab No 3, design a Lexical Analyser to implement the
// following symbol tables.
// a. local symbol table
// b. global symbol table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "la.h"

#define TABLE_SIZE 100

struct node
{
  char lexeme[100];
  struct node *next;
};

struct entry
{
  int index;
  char lexeme[100];
  char type[30];
  char dtype[30];
  int row, col;
};

struct node *HashMap[TABLE_SIZE] = {NULL};
struct entry SymbolTable[TABLE_SIZE];
int symbolCount = 0;

const char *Datatypes[] = {"int", "float", "char", "double", "void"};
char currentDtype[30] = "NULL";

// Hash function
unsigned long hash(unsigned char *str)
{
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash % TABLE_SIZE;
}

// Check if a string is a data type
int isDtype(char *str)
{
  for (int i = 0; i < sizeof(Datatypes) / sizeof(char *); i++)
  {
    if (strcmp(str, Datatypes[i]) == 0)
      return 1;
  }
  return 0;
}

// Insert into hash map
void insertToHash(char *str)
{
  int hashVal = hash((unsigned char *)str);
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  strcpy(newNode->lexeme, str);
  newNode->next = HashMap[hashVal];
  HashMap[hashVal] = newNode;
}

// Search in hash map
int searchInHash(char *str)
{
  int hashVal = hash((unsigned char *)str);
  struct node *temp = HashMap[hashVal];
  while (temp)
  {
    if (strcmp(temp->lexeme, str) == 0)
      return 1;
    temp = temp->next;
  }
  return 0;
}

// Insert into symbol table
void insertSymbol(struct token tkn)
{
  if (searchInHash(tkn.lexeme) == 0)
  {
    insertToHash(tkn.lexeme);
    SymbolTable[symbolCount].index = symbolCount + 1;
    strcpy(SymbolTable[symbolCount].lexeme, tkn.lexeme);
    strcpy(SymbolTable[symbolCount].type, tkn.type);
    strcpy(SymbolTable[symbolCount].dtype, currentDtype); // Set dtype
    SymbolTable[symbolCount].row = tkn.row;
    SymbolTable[symbolCount].col = tkn.col;
    symbolCount++;
  }
}

// Display symbol table
void displaySymbolTable()
{
  printf("\n\t\tSYMBOL TABLE\n");
  printf("-------------------------------------------------------------------------\n");
  printf("Index\tLexeme\t\tType\t\tDtype\t\tRow\tCol\n");
  printf("-------------------------------------------------------------------------\n");
  for (int i = 0; i < symbolCount; i++)
  {
    printf("%d\t%-15s%-15s%-15s%d\t%d\n",
           SymbolTable[i].index,
           SymbolTable[i].lexeme,
           SymbolTable[i].type,
           SymbolTable[i].dtype,
           SymbolTable[i].row,
           SymbolTable[i].col);
  }
}

int main()
{
  FILE *fp = fopen("demo.c", "r");
  if (!fp)
  {
    perror("File open failed");
    return 1;
  }
  struct token tkn;
  while (1)
  {
    tkn = getNextToken(fp);
    if (strcmp(tkn.type, "EOF") == 0)
      break;
    if (strcmp(tkn.type, "Keyword") == 0 && isDtype(tkn.lexeme))
    {
      strcpy(currentDtype, tkn.lexeme);
      continue;
    }
    if (strcmp(tkn.type, "Identifier") == 0 || strcmp(tkn.type, "Number") == 0 || strcmp(tkn.type, "StringLiteral") == 0)
    {
      insertSymbol(tkn);
    }
  }
  fclose(fp);
  displaySymbolTable();
  return 0;
}
