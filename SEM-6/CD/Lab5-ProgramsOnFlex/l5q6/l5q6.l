%{
#include <stdio.h>
#include <ctype.h>
%}
 
%start COMMENT
 
%%
 
"//".*               { printf("%s", yytext); }
"/*"                 { BEGIN(COMMENT); printf("%s", yytext); }
<COMMENT>"*/"       { BEGIN(INITIAL); printf("%s", yytext); }
<COMMENT>.           { printf("%s", yytext); }
<COMMENT>\n          { printf("%s", yytext); }
 
[a-z]                { putchar(yytext[0]); }
[A-Z]                { putchar(tolower(yytext[0])); }
 
.                     { putchar(yytext[0]); }
 
%%
 
int main(int argc, char *argv[]) {
if (argc > 1) {
FILE *file = fopen(argv[1], "r");
if (file) {
yyin = file;
yylex();
fclose(file);
} else {
perror("Error opening file");
}
} else {
yylex();
}
return 0;
}
int yywrap(){ return 1; }
