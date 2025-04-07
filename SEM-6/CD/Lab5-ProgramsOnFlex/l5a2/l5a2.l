// Write a flex program to identify verb, noun and pronoun

%{
#include <stdio.h>
#include <string.h>

int is_verb(const char *word) {
    const char *verbs[] = {"run", "walk", "talk", "go", "come", "eat", "drink", "play", "write", "read"};
    for (int i = 0; i < sizeof(verbs)/sizeof(verbs[0]); i++) {
        if (strcmp(word, verbs[i]) == 0) return 1;
    }
    return 0;
}

int is_noun(const char *word) {
    const char *nouns[] = {"dog", "cat", "book", "apple", "boy", "girl", "car", "school", "tree", "city"};
    for (int i = 0; i < sizeof(nouns)/sizeof(nouns[0]); i++) {
        if (strcmp(word, nouns[i]) == 0) return 1;
    }
    return 0;
}

int is_pronoun(const char *word) {
    const char *pronouns[] = {"he", "she", "it", "they", "we", "i", "you", "him", "her", "us", "them"};
    for (int i = 0; i < sizeof(pronouns)/sizeof(pronouns[0]); i++) {
        if (strcmp(word, pronouns[i]) == 0) return 1;
    }
    return 0;
}
%}

%%

[a-zA-Z]+ {
    if (is_verb(yytext))
        printf("VERB => %s\n", yytext);
    else if (is_noun(yytext))
        printf("NOUN => %s\n", yytext);
    else if (is_pronoun(yytext))
        printf("PRONOUN => %s\n", yytext);
    else
        printf("UNKNOWN => %s\n", yytext);
}

[ \t\n]+ ;  // Ignore whitespace

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a sentence:\n");
    yylex();
    return 0;
}

