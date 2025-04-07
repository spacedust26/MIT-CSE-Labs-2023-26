/* Count the number of vowels and consonants in the given input*/

%{
  int vowels = 0;
  int consonants = 0;
%}
%%
  [aeiouAEIOU] {vowels++;}
  [a-zA-Z] {consonants++;}
%%

int yywrap(){
  return 1;
}

int main(){
  printf("Enter string: ");
  yylex();
  printf("Vowels = %d Consonants = %d\n", vowels, consonants);
  return 0;
}
