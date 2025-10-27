#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack operations
void push1(int val) { stack1[++top1] = val; }
void push2(int val) { stack2[++top2] = val; }
int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }
int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }

// Queue operations
void enqueue(int val) {
    push1(val);
    printf("Enqueued: %d\n", val);
}

void dequeue() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is empty!\n");
        return;
    }

    // Move all from stack1 to stack2 if stack2 is empty
    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }

    int val = pop2();
    printf("Dequeued: %d\n", val);
}

void peek() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is empty!\n");
        return;
    }

    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }

    printf("Front element: %d\n", stack2[top2]);
}

void display() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (Front → Rear): ");
    for (int i = top2; i >= 0; i--) printf("%d ", stack2[i]);
    for (int i = 0; i <= top1; i++) printf("%d ", stack1[i]);
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Queue Using Two Stacks ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
