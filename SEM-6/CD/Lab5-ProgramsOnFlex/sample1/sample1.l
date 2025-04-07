// Program to count the number of characters, words and lines

%{
  #include <stdio.h>
  #include <string.h>
  int chars = 0;
  int words = 0;
  int lines = 0;
%}

%%
  [a-zA-Z]+ { words++; chars += strlen(yytext); }
  \n { lines++; }
  . { chars++; }
%%

int yywrap(){
  return 1;
} 

int main(int argc, char **argv){
  yylex();
  printf("Lines: %d Words: %d Characters: %d\n", lines, words, chars);
  return 0;
}
