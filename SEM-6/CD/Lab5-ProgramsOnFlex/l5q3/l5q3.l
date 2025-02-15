/*Find the number of positive integer, negative integer, positive floating point number and negative floating point number*/
%{
int posint = 0;
int negint = 0;
int posfloat = 0;
int negfloat = 0;
%}
%%
^[-][0-9]+ {negint++;}
[0-9]+ {posint++;}
^[-][0-9]+[.][0-9]+ {negfloat++;}
[0-9]+[.][0-9]+ {posfloat++;}
%%
int main(int argc, char **argv)
{
yylex();
printf("Total count of \n Postive Integers: %d\n Negative Integers: %d\n Postive Floating Point Numbers: %d\n Negative Flaoting Point Numbers: %d\n", posint, negint, posfloat, negfloat); 
}
int yywrap()
{
return 1;
}