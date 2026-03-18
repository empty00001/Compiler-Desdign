#include <stdio.h>

char input[20];
int pos = 0;
int invalid = 0;

void E();
void Eprime();

int main() {
    printf("Enter input string (end with $): ");
    scanf("%s", input);
    E();
    if (input[pos] == '$' && invalid == 0)
        printf("Valid String\n");
    else
        printf("Invalid String\n");
    return 0;
}

void E() {
    if (input[pos] == 'i') {
        pos++;
        Eprime();
    } else {
        invalid = 1;
    }
}

void Eprime() {
    if (input[pos] == '+') {
        pos++;
        if (input[pos] == 'i') {
            pos++;
            Eprime();
        } else {
            invalid = 1;
        }
    }
}