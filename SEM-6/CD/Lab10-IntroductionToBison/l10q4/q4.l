
%{

#include "q4.tab.h"

%}



%%



[0-9]+ { yylval.num = atoi(yytext); return NUM; }

[\n] { return yytext[0]; }

[+\-*/^n] { return yytext[0]; }

[ \t] { /* ignore whitespace */ }

. { printf("Unexpected character: %s\n", yytext); }



%%



int yywrap(void) {

 return 1;

}