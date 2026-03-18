#include <stdio.h>
#include <string.h>

char stack[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop() {
    top--;
    stack[top + 1] = '\0';
}

char precedence(char a, char b) {
    if (a == '$' && b == '$') return '=';
    if (a == '$') return '<';
    if (b == '$') return '>';
    if (a == 'i' && b == 'i') return ' ';
    if (a == 'i') return '>';
    if (b == 'i') return '<';
    if (a == '+' && b == '+') return '>';
    if (a == '+' && b == '*') return '<';
    if (a == '*' && b == '+') return '>';
    if (a == '*' && b == '*') return '>';
    return ' ';
}

int main() {
    char input[20];
    int i = 0;
    char a, b;

    printf("Enter the input string (end with $): ");
    scanf("%s", input);
    push('$');

    printf("\nStack\tInput\tAction\n");
    while (1) {
        a = stack[top];
        b = input[i];
        printf("%s\t%s\t", stack, &input[i]);

        if (a == '$' && b == '$') {
            printf("Accept\n");
            break;
        }

        char prec = precedence(a, b);
        if (prec == '<' || prec == '=') {
            push(b);
            i++;
            printf("Shift\n");
        } else if (prec == '>') {
            pop();
            printf("Reduce\n");
        } else {
            printf("Error\n");
            break;
        }
    }
    return 0;
}