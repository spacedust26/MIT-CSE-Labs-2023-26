
%%
[a-zA-Z_][a-zA-Z0-9_]* printf(" Identifier");
%%
int yywrap() { return 1;}

int main(int argc, char **argv)
{
    yylex();
}