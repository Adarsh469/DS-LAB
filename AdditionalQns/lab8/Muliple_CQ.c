#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define NQ 3  // number of queues

int A[MAX];
int front[NQ], rear[NQ];
int start[NQ], end[NQ];
int total_size = MAX;

void init_queues() {
    int segment = total_size / NQ;
    for (int i = 0; i < NQ; i++) {
        start[i] = i * segment;
        end[i] = (i + 1) * segment - 1;
        front[i] = rear[i] = -1;
    }
}

int QUEUE_FULL(int i) {
    return (front[i] == (rear[i] + 1) % (end[i] - start[i] + 1));
}

int QUEUE_EMPTY(int i) {
    return (front[i] == -1);
}

void ADDQ(int i, int x) {
    if (QUEUE_FULL(i)) {
        printf("Queue %d is full!\n", i + 1);
        return;
    }

    if (front[i] == -1)
        front[i] = rear[i] = 0;
    else
        rear[i] = (rear[i] + 1) % (end[i] - start[i] + 1);

    int pos = start[i] + rear[i];
    A[pos] = x;

    printf("Added %d to Queue %d\n", x, i + 1);
}

void DELETEQ(int i) {
    if (QUEUE_EMPTY(i)) {
        printf("Queue %d is empty!\n", i + 1);
        return;
    }

    int pos = start[i] + front[i];
    printf("Deleted %d from Queue %d\n", A[pos], i + 1);

    if (front[i] == rear[i])
        front[i] = rear[i] = -1;
    else
        front[i] = (front[i] + 1) % (end[i] - start[i] + 1);
}

void DISPLAYQ(int i) {
    if (QUEUE_EMPTY(i)) {
        printf("Queue %d is empty!\n", i + 1);
        return;
    }

    printf("Queue %d elements: ", i + 1);
    int size = end[i] - start[i] + 1;
    int idx = front[i];
    while (1) {
        printf("%d ", A[start[i] + idx]);
        if (idx == rear[i]) break;
        idx = (idx + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice, q, val;
    init_queues();

    while (1) {
        printf("\n--- Multiple Queues in Single Array ---\n");
        printf("1. ADDQ (Enqueue)\n2. DELETEQ (Dequeue)\n3. DISPLAYQ\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number (1-%d): ", NQ);
                scanf("%d", &q);
                printf("Enter value: ");
                scanf("%d", &val);
                ADDQ(q - 1, val);
                break;
            case 2:
                printf("Enter queue number (1-%d): ", NQ);
                scanf("%d", &q);
                DELETEQ(q - 1);
                break;
            case 3:
                for (int i = 0; i < NQ; i++)
                    DISPLAYQ(i);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
