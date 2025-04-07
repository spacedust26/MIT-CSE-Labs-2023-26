// Generate tokens for a simple C program (Tokens to be considered are: Keywords, Identifiers, Special Symbols, Arithmetic operators and logical operators)

%{
  #include <stdio.h>
  #include <stdlib.h>
%}

int is_keyword(const char *word){
  const char *keywords[] = {"int", "char", "float", "double", "if", "else", "for", "while", "do", "return", "void", "break", "continue", "switch", "case", "default", "struct", "union", "typedef", "const", "static", "enum", "sizeof"};
  int n = sizeof(keywords) / sizeof(keywords[0]);
  for(int i = 0; i < n; i++){
    if(strcmp(word, keywords[i]) == 0) return 1;
  }
  return 0;
}

%%
"&&" { printf("LOGICAL OPERATOR %s\n", yytext);}
"||" { printf("LOGICAL OPERATOR %s\n", yytext);}
"!" { printf("LOGICAL OPERATOR %s\n", yytext);}
(\+|\-|\*|\/|%) { printf("ARITHMETIC OPERATOR %s\n", yytext);}
[\(\)\{\};,\[\]] { printf("SPECIAL SYMBOL %s\n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]*{
  if(is_keyword(yytext)) printf("KEYWORD %s\n", yytext);
  else printf("IDENTIFIER %s\n", yytext);
}
[ \t\r\n]+ ;
. { printf("UNKNOWN %s\n", yytext);}
%%

int yywrap(){
  return 1;
}

int main(){
  printf("Enter C code (Ctrl + D to end):\n");
  yylex();
  return 0;
}