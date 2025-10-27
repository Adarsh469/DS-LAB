#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10

struct PrintJob {
    int id;
    char name[50];
};

struct PrintJob queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1;
}

void enqueue(struct PrintJob job) {
    if (isFull()) {
        printf("Queue is full. Cannot add job %s!\n", job.name);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = job;
    printf("Enqueued: Job ID %d - %s\n", job.id, job.name);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    struct PrintJob job = queue[front];
    printf("Printing Job ID %d - %s...\n", job.id, job.name);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("\nCurrent Printer Queue:\n");
    for (int i = front; i <= rear; i++)
        printf("Job ID %d - %s\n", queue[i].id, queue[i].name);
}

int main() {
    int choice;
    struct PrintJob job;
    srand(time(0));

    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Print Job\n2. Print Next Job\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                job.id = rand() % 1000;
                printf("Enter document name: ");
                fgets(job.name, sizeof(job.name), stdin);
                job.name[strcspn(job.name, "\n")] = 0;
                enqueue(job);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
