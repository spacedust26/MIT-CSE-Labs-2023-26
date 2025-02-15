#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct token {
    char lexeme[64];
    int row, col;
    char type[30];
};

static int row = 1, col = 1;
char specialsymbols[] = {'?', ';', ':', ',', '(', ')', '{', '}', '.'};
char *Keywords[] = {"for", "if", "else", "while", "do", "break", "continue", "return", "int", "double", "float", "char", "long", "short", "sizeof", "typedef", "switch", "case", "struct", "const", "void", "exit"};
char arithmeticsymbols[] = {'*','+','-','/', '%'};

int isKeyword(char *str) {
    for (int i = 0; i < sizeof(Keywords) / sizeof(char *); i++) {
        if (strcmp(str, Keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int charBelongsTo(int c, char *arr, int len) {
    for (int i = 0; i < len; i++) {
        if (c == arr[i])
            return 1;
    }
    return 0;
}

void fillToken(struct token *tkn, char c, int row, int col, char *type) {
    tkn->row = row;
    tkn->col = col;
    strcpy(tkn->type, type);
    tkn->lexeme[0] = c;
    tkn->lexeme[1] = '\0';
}

void newLine() {
    ++row;
    col = 1;
}

struct token getNextToken(FILE *fin) {
    int c, d;
    struct token tkn = {.row = -1};
    int gotToken = 0;

    while (!gotToken && (c = getc(fin)) != EOF) {
        // SKIP COMMENTS
        if (c == '/') {
            d = getc(fin);
            if (d == '/') {  // Skip single-line comments
                while ((c = getc(fin)) != EOF && c != '\n') ++col;
                if (c == '\n') newLine();
                continue;
            } else if (d == '*') {  // Skip multi-line comments
                do {
                    if (c == '\n') newLine();
                    while ((c = getc(fin)) != EOF && c != '*') {
                        if (c == '\n') newLine();
                    }
                    if (c == '*') d = getc(fin);
                } while (c != EOF && d != '/');
                continue;
            } else {
                fseek(fin, -1, SEEK_CUR);  // Not a comment
            }
        }

        // Handle preprocessor directives (lines starting with '#')
        if (c == '#') {
            tkn.row = row;
            tkn.col = col++;
            tkn.lexeme[0] = '#';
            int k = 1;
            while ((c = getc(fin)) != '\n' && !isspace(c)) {
                tkn.lexeme[k++] = c;
                col++;
            }
            tkn.lexeme[k] = '\0';  // Null-terminate the lexeme

            // Process #include directive
            if (strcmp(tkn.lexeme, "#include") == 0) {
                c = getc(fin); ++col;
                if (c == '<' || c == '"') {
                    while ((c = getc(fin)) != EOF && c != (c == '<' ? '>' : '"')) ++col;
                    if (c != EOF) {
                        while ((c = getc(fin)) != '\n') ++col;  // Skip the rest of the line
                        newLine();
                    }
                    continue;
                } else {
                    // Invalid #include
                    strcpy(tkn.type, "InvalidDirective");
                    strcat(tkn.lexeme, "<invalid>");
                    while ((c = getc(fin)) != '\n') {
                        strncat(tkn.lexeme, (char*)&c, 1);
                        ++col;
                    }
                    newLine();
                    gotToken = 1;
                }
            }
        }

        // Process special symbols
        if (charBelongsTo(c, specialsymbols, sizeof(specialsymbols) / sizeof(char))) {
            fillToken(&tkn, c, row, col, (char[]){c, '\0'});
            gotToken = 1;
            ++col;
        }

        // Process arithmetic operators
        else if (charBelongsTo(c, arithmeticsymbols, sizeof(arithmeticsymbols) / sizeof(char))) {
            d = getc(fin);
            if (d == '=' || (c == '+' || c == '-') && d == c) {
                fillToken(&tkn, c, row, col, (char[]){c, c == '=' ? '=' : '\0', '\0'});
                col += 2;
            } else {
                fillToken(&tkn, c, row, col, (char[]){c, '\0'});
                ++col;
                fseek(fin, -1, SEEK_CUR);
            }
            gotToken = 1;
        }

        // Process relational operators
        else if (c == '=' || c == '<' || c == '>' || c == '!') {
            d = getc(fin);
            if (d == '=') {
                fillToken(&tkn, c, row, col, (char[]){c, '=', '\0'});
                col += 2;
            } else {
                fillToken(&tkn, c, row, col, (char[]){c, '\0'});
                ++col;
                fseek(fin, -1, SEEK_CUR);
            }
            gotToken = 1;
        }

        // Process numbers
        else if (isdigit(c)) {
            tkn.row = row;
            tkn.col = col++;
            tkn.lexeme[0] = c;
            int k = 1;
            while ((c = getc(fin)) != EOF && isdigit(c)) {
                tkn.lexeme[k++] = c;
                ++col;
            }
            tkn.lexeme[k] = '\0';
            strcpy(tkn.type, "Number");
            gotToken = 1;
            fseek(fin, -1, SEEK_CUR);
        }

        // Discard whitespaces
        else if (isspace(c)) {
            ++col;
        }

        // Process keywords and identifiers
        else if (isalpha(c) || c == '_') {
            tkn.row = row;
            tkn.col = col++;
            tkn.lexeme[0] = c;
            int k = 1;
            while ((c = getc(fin)) != EOF && isalnum(c)) {
                tkn.lexeme[k++] = c;
                ++col;
            }
            tkn.lexeme[k] = '\0';
            strcpy(tkn.type, isKeyword(tkn.lexeme) ? "Keyword" : "Identifier");
            gotToken = 1;
            fseek(fin, -1, SEEK_CUR);
        }

        // Process String Literals
        else if (c == '"') {
            tkn.row = row;
            tkn.col = col;
            strcpy(tkn.type, "StringLiteral");
            int k = 1;
            tkn.lexeme[0] = '"';
            while ((c = getc(fin)) != EOF && c != '"') {
                tkn.lexeme[k++] = c;
                ++col;
            }
            tkn.lexeme[k] = '"';
            gotToken = 1;
        }

        else {
            ++col;
        }
    }
    return tkn;
}