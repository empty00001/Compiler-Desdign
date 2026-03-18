#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lexicalAnalyzer(char *code) {
    char *keywords[] = {"if","else","while","for","int","float","return","char","void"};
    int n_keywords = sizeof(keywords)/sizeof(keywords[0]);

    char token[100];
    int i=0,j=0;

    while(code[i] != '\0') {
        if(isspace(code[i])) { i++; continue; }

        if(strchr("+-*/=><!", code[i])) {
            if((code[i]=='='||code[i]=='!'||code[i]=='<'||code[i]=='>') && code[i+1]=='=') {
                printf("Operator: %c%c\n", code[i], code[i+1]);
                i+=2;
            } else {
                printf("Operator: %c\n", code[i]);
                i++;
            }
            continue;
        }

        if(strchr("();{}[],", code[i])) {
            printf("Delimiter: %c\n", code[i]);
            i++;
            continue;
        }

        if(isalnum(code[i]) || code[i]=='_') {
            j=0;
            while(isalnum(code[i]) || code[i]=='_' || code[i]=='.')
                token[j++] = code[i++];
            token[j]='\0';

            int isKeyword=0;
            for(int k=0;k<n_keywords;k++){
                if(strcmp(token,keywords[k])==0){
                    printf("Keyword: %s\n",token);
                    isKeyword=1; break;
                }
            }

            if(!isKeyword){
                if(isdigit(token[0])){
                    if(strchr(token,'.'))
                        printf("Float Number: %s\n",token);
                    else
                        printf("Integer Number: %s\n",token);
                } else {
                    printf("Identifier: %s\n",token);
                }
            }
        } else i++;
    }
}

int main() {
    char code[256];

    printf("Name : Parth Chokashi\n");
    printf("Enrollment No : 2403031057019\n\n");

    printf("Enter code: ");
    fgets(code, sizeof(code), stdin);

    printf("\nLexical Analysis Result:\n");
    lexicalAnalyzer(code);

    return 0;
}