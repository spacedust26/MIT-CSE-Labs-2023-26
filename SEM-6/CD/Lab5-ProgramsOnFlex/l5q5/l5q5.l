/*Write a flex program that changes a number from decimal to hexadecimal notation.*/


%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%%
[0-9]+ {int decimal = atoi(yytext);
        printf("Decimal: %s -> Hex: 0x%X\n", yytext, decimal);}
%%

int yywrap(){
    return -1;
}

int main(){
    printf("Enter decimal numbers:\n");
    yylex();
    return 0;
}