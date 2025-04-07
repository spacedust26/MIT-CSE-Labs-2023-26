// Convert uppercase characters to lowercase characters of C file excluding the characters present in the comment

%{
#include <stdio.h>
#include <ctype.h>
%}
 
%x COMMENT
%x LINECOMMENT

%%
"/*" {BEGIN(COMMENT); printf("/*");}
"//" {BEGIN(LINECOMMENT); printf("//");}
<COMMENT>{
  "*/" {BEGIN(INITIAL); printf("*/");}
  .|\n {putchar(yytext[0]);}
}
<LINECOMMENT>{
  \n {BEGIN(INITIAL); putchar('\n');}
  . {putchar(yytext[0]);}
}
[A-Z] {putchar(tolower(yytext[0]));}
.|\n {putchar(yytext[0]);}
%%

int yywrap(){
  return 1;
}

int main(int argc, char **argv){
  yyin = fopen(argv[1], "r");
  yylex();
  return 0;
}