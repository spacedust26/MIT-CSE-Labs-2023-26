/* Count the number of vowels and consonants in teh given input*/
%{
int vowels = 0;
int consonants = 0;
%}
%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {consonants++;}
%%
int yywrap(){}
int main(int argc, char **argv)
{
yylex();
printf("Enter the string of vowels and consonants:");
    yylex();
    printf("Number of vowels are:  %d\n", vowels);
    printf("Number of consonants are:  %d\n", consonants);
    return 0;
}