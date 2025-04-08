// Program         → main ( ) { declarations assign_stat }
// declarations    → data-type identifier-list ; declarations | ε
// data-type       → int | char
// identifier-list → id | id , identifier-list
// assign_stat     → id = id ; | id = num ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "la.h"

struct token tkn;
FILE *fp;

void program();
void declarations();
void data_type();
void identifier_list();
void assign_stat();

void syntaxError(char *expected)
{
  printf("Syntax error at row %d, col %d: expected %s but found %s\n", tkn.row, tkn.col, expected, tkn.lexeme);
  exit(1);
}

void match(char *expected)
{
  if (strcmp(tkn.lexeme, expected) == 0)
  {
    tkn = getNextToken(fp);
  }
  else
  {
    syntaxError(expected);
  }
}

void program()
{
  match("main");
  match("(");
  match(")");
  match("{");
  declarations();
  assign_stat();
  match("}");
  printf("-------------Parsing successful----------\n");
}

void declarations()
{
  if (strcmp(tkn.lexeme, "int") == 0 || strcmp(tkn.lexeme, "char") == 0)
  {
    data_type();
    identifier_list();
    match(";");
    declarations();
  }
  // ε production handled by falling through when token is not int or char
}

void data_type()
{
  if (strcmp(tkn.lexeme, "int") == 0 || strcmp(tkn.lexeme, "char") == 0)
  {
    tkn = getNextToken(fp);
  }
  else
  {
    syntaxError("int or char");
  }
}

void identifier_list()
{
  if (strcmp(tkn.type, "Identifier") == 0)
  {
    tkn = getNextToken(fp);
    if (strcmp(tkn.lexeme, ",") == 0)
    {
      tkn = getNextToken(fp);
      identifier_list();
    }
  }
  else
  {
    syntaxError("Identifier");
  }
}

void assign_stat()
{
  if (strcmp(tkn.type, "Identifier") == 0)
  {
    tkn = getNextToken(fp);
    match("=");
    if (strcmp(tkn.type, "Identifier") == 0 || strcmp(tkn.type, "Number") == 0)
    {
      tkn = getNextToken(fp);
      match(";");
    }
    else
    {
      syntaxError("Identifier or Number");
    }
  }
  else
  {
    syntaxError("Identifier");
  }
}

int main()
{
  fp = fopen("input.c", "r");
  if (!fp)
  {
    printf("Error in opening file\n");
    return 1;
  }

  tkn = getNextToken(fp);
  program();
  return 0;
}
