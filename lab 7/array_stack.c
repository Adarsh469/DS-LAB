#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation using array
char stack[MAX];
int top = -1;

// Stack operations
void push(char ch) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

char peek() {
    return (top == -1) ? '\0' : stack[top];
}

void clearStack() {
    top = -1;
}

// Function 1: Check Palindrome
void checkPalindrome() {
    char str[MAX];
    clearStack();
    printf("\nEnter a string: ");
    scanf("%s", str);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        push(tolower(str[i]));

    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) != pop()) {
            printf("Not a palindrome.\n");
            return;
        }
    }
    printf("Palindrome string.\n");
}

// Function 2: Matching Parentheses
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

void checkParentheses() {
    char expr[MAX];
    clearStack();
    printf("\nEnter an expression: ");
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatchingPair(pop(), ch)) {
                printf("Unbalanced parentheses.\n");
                return;
            }
        }
    }

    if (top == -1)
        printf("Balanced parentheses.\n");
    else
        printf("Unbalanced parentheses.\n");
}

// MAIN MENU
int main() {
    int choice;

    while (1) {
        printf("\n=== ARRAY-BASED STACK MENU ===\n");
        printf("1. Check Palindrome\n");
        printf("2. Check Matching Parentheses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkPalindrome();
                break;
            case 2:
                checkParentheses();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
