
%{
#include "q3.tab.h"
#include <stdlib.h>
%}
%%
[0-9]+ { yylval = atoi(yytext); return NUM; }
"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"(" { return LPAREN; }
")" { return RPAREN; }
[ \t] ; /* Ignore whitespace */
\n { return EOL; }
. { printf("Invalid character: %s\n", yytext); }
%%
int yywrap() {
 return 1;
}