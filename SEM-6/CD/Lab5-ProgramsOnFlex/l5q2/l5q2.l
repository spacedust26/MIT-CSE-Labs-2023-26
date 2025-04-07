// Count the number of words, characters, blanks and lines in a given text

%{
  #include <stdio.h>
  #include <string.h>
  int chars = 0;
  int words = 0;
  int lines = 0;
  int blank = 0;
%}

%%
  [a-zA-Z]+ { words++; chars += strlen(yytext); }
  \n { lines++; }
  [ ,/t] {blank++; }
  . { chars++; }
%%

int yywrap(){
  return 1;
}

int main(){
  printf("Enter text (Ctrl + D to end):\n");
  yylex();
  printf("Lines: %d Words: %d Characters: %d Blank: %d \n", lines, words, chars, blank); 
  return 0;
}
