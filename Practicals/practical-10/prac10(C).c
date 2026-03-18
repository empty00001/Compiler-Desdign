%{
#include<stdio.h>
int line_number = 1;
%}

line .*\n

%%
{line} { printf("%d %s", line_number++, yytext); }
%%

int main() {
    extern FILE *yyin;
    yyin = fopen("add.txt", "r");
    if (yyin == NULL) {
        printf("File Not Found");
    }
    yylex();
    return 0;
}

int yywrap() { return 1; }