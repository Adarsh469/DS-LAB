#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int arr[SIZE];
int top1 = -1, top2 = SIZE;

// Push into stack 1
void push1(int val) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[++top1] = val;
}

// Push into stack 2
void push2(int val) {
    if (top2 - 1 == top1) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[--top2] = val;
}

// Pop from stack 1
int pop1() {
    if (top1 == -1) {
        printf("Stack 1 Underflow!\n");
        return -1;
    }
    return arr[top1--];
}

// Pop from stack 2
int pop2() {
    if (top2 == SIZE) {
        printf("Stack 2 Underflow!\n");
        return -1;
    }
    return arr[top2++];
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Multiple Stacks Menu ---\n");
        printf("1. Push Stack 1\n2. Push Stack 2\n3. Pop Stack 1\n4. Pop Stack 2\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push1(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                push2(val);
                break;
            case 3:
                val = pop1();
                if (val != -1) printf("Popped from Stack 1: %d\n", val);
                break;
            case 4:
                val = pop2();
                if (val != -1) printf("Popped from Stack 2: %d\n", val);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
