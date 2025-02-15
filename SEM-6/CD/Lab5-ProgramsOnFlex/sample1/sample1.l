%{
int chars = 0;
int words = 0;
int lines = 0;
%}
%%
[a-zA-Z]+ { words++; chars += strlen(yytext); }
\n { ines++; }
. { chars++; }
%%
main(int argc, char **argv)
{
yylex();
printf("Lines: %d Words: %d Characters: %d\n", lines, words, chars); }
int yywrap()
{
return 1;
}