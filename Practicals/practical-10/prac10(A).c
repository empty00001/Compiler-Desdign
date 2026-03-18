%{
#include<stdio.h>
#include<stdlib.h>
int num = 0;
FILE *yyin;
%}

%%
[0-9]+  { num++; ECHO; }
.|\n    { ECHO; }
%%

int main(void) {
    yyin = fopen("practical10.txt", "r");
    if (yyin == NULL) {
        printf("File not found\n");
        return 1;
    }
    yylex();
    printf("\n\t%d digits\n", num);
    fclose(yyin);
    return 0;
}

int yywrap() { return 1; }