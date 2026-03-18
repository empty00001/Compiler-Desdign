#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[50];
int top = -1;
char input[50];
int ip = 0;

char action[12][6][10] = {
    {"s5", "", "s4", "", "", ""},
    {"", "s6", "", "", "", "acc"},
    {"", "r2", "s7", "", "r2", "r2"},
    {"", "r4", "", "r4", "r4", "r4"},
    {"s5", "", "s4", "", "", ""},
    {"", "r6", "r6", "", "r6", "r6"},
    {"s5", "", "s4", "", "", ""},
    {"s5", "", "s4", "", "", ""},
    {"", "s6", "", "s11", "", ""},
    {"", "r1", "s7", "", "r1", "r1"},
    {"", "r3", "r3", "", "r3", "r3"},
    {"", "r5", "r5", "", "r5", "r5"}
};

char goto_table[12][3][10] = {
    {"1", "2", "3"}, {"", "", ""}, {"", "", ""}, {"", "", ""},
    {"8", "2", "3"}, {"", "", ""}, {"", "9", "3"}, {"", "", "10"},
    {"", "", ""}, {"", "", ""}, {"", "", ""}, {"", "", ""}
};

char terminals[] = {'i', '+', '*', '(', ')', '$'};
char nonterminals[] = {'E', 'T', 'F'};

struct grammar {
    char left;
    char right[10];
} rules[] = {
    {'E', "E+T"}, {'E', "T"}, {'T', "T*F"}, {'T', "F"}, {'F', "(E)"}, {'F', "i"}
};

void push(char c) { stack[++top] = c; }
void pop() { top--; }

int getTerminalIndex(char c) {
    for (int i = 0; i < 6; i++) if (terminals[i] == c) return i;
    return -1;
}

int getNonTerminalIndex(char c) {
    for (int i = 0; i < 3; i++) if (nonterminals[i] == c) return i;
    return -1;
}

int getState() { return stack[top] - '0'; }

void displayStack() {
    for (int i = 0; i <= top; i++) printf("%c", stack[i]);
}

int main() {
    char act[10];
    printf("Enter input string: ");
    scanf("%s", input);
    strcat(input, "$");
    push('0');
    printf("\nStack\t\tInput\t\tAction\n");
    while (1) {
        int state = getState();
        int tindex = getTerminalIndex(input[ip]);
        strcpy(act, action[state][tindex]);
        displayStack();
        printf("\t\t%s\t\t", input + ip);
        if (strcmp(act, "acc") == 0) {
            printf("ACCEPT\n");
            break;
        } else if (act[0] == 's') {
            printf("SHIFT %c\n", act[1]);
            push(input[ip]);
            push(act[1]);
            ip++;
        } else if (act[0] == 'r') {
            int r = act[1] - '1';
            printf("REDUCE by %c -> %s\n", rules[r].left, rules[r].right);
            int len = strlen(rules[r].right);
            for (int i = 0; i < len * 2; i++) pop();
            state = getState();
            int ntindex = getNonTerminalIndex(rules[r].left);
            push(rules[r].left);
            push(goto_table[state][ntindex][0]);
        } else {
            printf("ERROR\n");
            break;
        }
    }
    return 0;
}