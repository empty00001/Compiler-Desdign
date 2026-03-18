%{
#include<stdio.h>
int words = 0;
int lines = 0;
%}

%%
\n      { lines++; }
[a-zA-Z]+ { words++; }
%%

int main()
{
    yylex();
    printf("Words = %d\n", words);
    printf("Lines = %d\n", lines);
    return 0;
}

int yywrap()
{
    return 1;
}