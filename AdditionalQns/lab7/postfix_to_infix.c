#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

void postfixToInfix(char *postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            char temp[2] = {c, '\0'};
            push(temp);
        } else {
            char op2[MAX], op1[MAX], expr[MAX];
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(expr, "(%s%c%s)", op1, c, op2);
            push(expr);
        }
    }
    printf("Fully Parenthesized Infix: %s\n", stack[top]);
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix);
    return 0;
}
