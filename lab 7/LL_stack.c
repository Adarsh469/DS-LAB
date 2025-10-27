#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *top = NULL;

// Stack operations
void push(char ch) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL)
        return '\0';
    char ch = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return ch;
}

char peek() {
    return (top == NULL) ? '\0' : top->data;
}

void clearStack() {
    while (top)
        pop();
}

// Function 1: Infix to Postfix Conversion
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix() {
    char infix[100], postfix[100];
    int j = 0;
    clearStack();

    printf("\nEnter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else {
            while (top && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

// Function 2: Evaluate Postfix Expression
struct EvalNode {
    int data;
    struct EvalNode *next;
};
struct EvalNode *evalTop = NULL;

void evalPush(int val) {
    struct EvalNode *newNode = (struct EvalNode*)malloc(sizeof(struct EvalNode));
    newNode->data = val;
    newNode->next = evalTop;
    evalTop = newNode;
}

int evalPop() {
    if (evalTop == NULL) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    int val = evalTop->data;
    struct EvalNode *temp = evalTop;
    evalTop = evalTop->next;
    free(temp);
    return val;
}

void evaluatePostfix() {
    char expr[100];
    printf("\nEnter postfix expression: ");
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            evalPush(ch - '0');
        } else {
            int val2 = evalPop();
            int val1 = evalPop();
            switch (ch) {
                case '+': evalPush(val1 + val2); break;
                case '-': evalPush(val1 - val2); break;
                case '*': evalPush(val1 * val2); break;
                case '/': evalPush(val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return;
            }
        }
    }
    printf("Result = %d\n", evalPop());
}

// MAIN MENU
int main() {
    int choice;

    while (1) {
        printf("\n=== LINKED LIST STACK MENU ===\n");
        printf("1. Infix to Postfix Conversion\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                infixToPostfix();
                break;
            case 2:
                evaluatePostfix();
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
