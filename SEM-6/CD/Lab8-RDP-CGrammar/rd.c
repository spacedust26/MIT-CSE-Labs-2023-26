// Program           → main ( ) { Declarations StatementList }
// Declarations      → DataType IdentifierList ; Declarations | ε
// DataType          → int | char
// IdentifierList    → id
//                   | IdentifierList , id
//                   | id [ number ]
//                   | IdentifierList , id [ number ]
// StatementList     → Statement StatementList | ε
// Statement         → AssignStat ;
//                   | DecisionStat
// AssignStat        → id = Expn
// DecisionStat      → if ( Expn ) { StatementList } Dprime
// Dprime            → else { StatementList } | ε
// Expn              → SimpleExpn Eprime
// Eprime            → Relop SimpleExpn | ε
// SimpleExpn        → Term Seprime
// Seprime           → Addop Term Seprime | ε
// Term              → Factor Tprime
// Tprime            → Mulop Factor Tprime | ε
// Factor            → id | num
// Relop             → == | != | <= | >= | < | >
// Addop             → + | -
// Mulop             → * | / | %

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "la.h"

FILE *fp;
struct token tkn;

void program();
void declarations();
void data_type();
void identifier_list();
void statement_list();
void statement();
void assign_stat();
void decision_stat();
void expn();
void eprime();
void simple_expn();
void seprime();
void term();
void tprime();
void factor();
void dprime();
void relop();
void addop();
void mulop();

void syntaxError(char *expected)
{
  printf("Syntax error at row %d, col %d: expected %s but found '%s'\n", tkn.row, tkn.col, expected, tkn.lexeme);
  exit(1);
}

void match(char *expected)
{
  if (strcmp(expected, tkn.lexeme) == 0)
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
  statement_list();
  match("}");
  printf("----------- Parsing successful -----------\n");
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
    if (strcmp(tkn.lexeme, "[") == 0)
    {
      match("[");
      if (strcmp(tkn.type, "Number") == 0)
      {
        tkn = getNextToken(fp);
        match("]");
      }
      else
      {
        syntaxError("Number");
      }
    }
    if (strcmp(tkn.lexeme, ",") == 0)
    {
      match(",");
      identifier_list();
    }
  }
  else
  {
    syntaxError("Identifier");
  }
}

void statement_list()
{
  if (strcmp(tkn.lexeme, "if") == 0 || strcmp(tkn.type, "Identifier") == 0)
  {
    statement();
    statement_list();
  }
}

void statement()
{
  if (strcmp(tkn.lexeme, "if") == 0)
    decision_stat();
  else if (strcmp(tkn.type, "Identifier") == 0)
    assign_stat();
  else
    syntaxError("if or Identifier");
}

void assign_stat()
{
  if (strcmp(tkn.type, "Identifier") == 0)
  {
    tkn = getNextToken(fp);
    match("=");
    expn();
    match(";");
  }
  else
  {
    syntaxError("Identifier");
  }
}

void expn()
{
  simple_expn();
  eprime();
}

void eprime()
{
  if (strcmp(tkn.lexeme, "==") == 0 || strcmp(tkn.lexeme, "!=") == 0 ||
      strcmp(tkn.lexeme, "<=") == 0 || strcmp(tkn.lexeme, ">=") == 0 ||
      strcmp(tkn.lexeme, "<") == 0 || strcmp(tkn.lexeme, ">") == 0)
  {
    relop();
    simple_expn();
  }
  // epsilon case handled implicitly
}

void simple_expn()
{
  term();
  seprime();
}

void seprime()
{
  if (strcmp(tkn.lexeme, "+") == 0 || strcmp(tkn.lexeme, "-") == 0)
  {
    addop();
    term();
    seprime();
  }
  // epsilon case handled implicitly
}

void term()
{
  factor();
  tprime();
}

void tprime()
{
  if (strcmp(tkn.lexeme, "*") == 0 || strcmp(tkn.lexeme, "/") == 0 || strcmp(tkn.lexeme, "%") == 0)
  {
    mulop();
    factor();
    tprime();
  }
  // epsilon case handled implicitly
}

void factor()
{
  if (strcmp(tkn.type, "Identifier") == 0 || strcmp(tkn.type, "Number") == 0)
  {
    tkn = getNextToken(fp);
  }
  else
  {
    syntaxError("Identifier or Number");
  }
}

void decision_stat()
{
  match("if");
  match("(");
  expn();
  match(")");
  match("{");
  statement_list();
  match("}");
  dprime();
}

void dprime()
{
  if (strcmp(tkn.lexeme, "else") == 0)
  {
    match("else");
    match("{");
    statement_list();
    match("}");
  }
  // epsilon handled implicitly
}

void relop()
{
  if (strcmp(tkn.lexeme, "==") == 0 || strcmp(tkn.lexeme, "!=") == 0 ||
      strcmp(tkn.lexeme, "<=") == 0 || strcmp(tkn.lexeme, ">=") == 0 ||
      strcmp(tkn.lexeme, "<") == 0 || strcmp(tkn.lexeme, ">") == 0)
  {
    tkn = getNextToken(fp);
  }
  else
  {
    syntaxError("Relational Operator");
  }
}

void addop()
{
  if (strcmp(tkn.lexeme, "+") == 0 || strcmp(tkn.lexeme, "-") == 0)
  {
    tkn = getNextToken(fp);
  }
  else
  {
    syntaxError("+ or -");
  }
}

void mulop()
{
  if (strcmp(tkn.lexeme, "*") == 0 || strcmp(tkn.lexeme, "/") == 0 || strcmp(tkn.lexeme, "%") == 0)
  {
    tkn = getNextToken(fp);
  }
  else
  {
    syntaxError("* or / or %");
  }
}

int main()
{
  fp = fopen("demo.c", "r");
  if (!fp)
  {
    printf("Error opening input file\n");
    return 1;
  }
  tkn = getNextToken(fp);
  program();
  return 0;
}