#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluate(char *prefix) {
    int n = strlen(prefix);
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c)) {
            push(c - '0');
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
            }
        }
    }
    return pop();
}

int main() {
    char prefix[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    printf("Result = %d\n", evaluate(prefix));
    return 0;
}
