%{
#include<stdio.h>
#include<stdlib.h>
int vow_count = 0;
int const_count = 0;
FILE *yyin;
%}

%%
[aeiouAEIOU]             { vow_count++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { const_count++; }
%%

int main() {
    yyin = fopen("practical9.txt", "r");
    if (yyin == NULL) {
        printf("File not found\n");
        return 1;
    }
    yylex();
    printf("The number of vowels are: %d\n", vow_count);
    printf("The number of consonants are: %d\n", const_count);
    fclose(yyin);
    return 0;
}

int yywrap() { return 1; }