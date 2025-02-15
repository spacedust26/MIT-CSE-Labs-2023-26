%{
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
int main(int argc, char **argv)
{
yylex();
printf("Lines: %d Words: %d Characters: %d Blank: %d \n", lines, words, chars, blank); }
int yywrap()
{
return 1;
}