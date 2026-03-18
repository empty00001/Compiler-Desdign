%{
#include<stdio.h>
#include<stdlib.h>
int tags = 0;
FILE *yyin;
%}

%%
"<"[^>]*">" { tags++; printf("%s\n", yytext); }
.|\n        {}
%%

int main(void) {
    char file[100];
    printf("Enter File Name: ");
    scanf("%s", file);
    FILE *f = fopen(file, "r");
    if (!f) {
        fprintf(stderr, "Error: Cannot open file %s\n", file);
        return 1;
    }
    yyin = f;
    yylex();
    printf("\nNumber of HTML tags: %d\n", tags);
    fclose(f);
    return 0;
}

int yywrap() { return 1; }