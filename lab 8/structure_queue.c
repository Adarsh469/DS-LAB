#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[50];
    int age;
    int priority; // 1 = High, 2 = Medium, 3 = Low
    struct Patient *next;
};

struct Patient *front = NULL, *rear = NULL;

void enqueue(struct Patient p) {
    struct Patient *newNode = (struct Patient*)malloc(sizeof(struct Patient));
    *newNode = p;
    newNode->next = NULL;

    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %s (Priority %d)\n", p.name, p.priority);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Patient *temp = front;
    printf("Now Serving: %s (Age %d, Priority %d)\n", temp->name, temp->age, temp->priority);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("\nPatient Queue:\n");
    struct Patient *ptr = front;
    while (ptr != NULL) {
        printf("Name: %-10s | Age: %2d | Priority: %d\n", ptr->name, ptr->age, ptr->priority);
        ptr = ptr->next;
    }
}

int main() {
    int choice;
    struct Patient p;

    while (1) {
        printf("\n--- Patient Queue Menu ---\n");
        printf("1. Add Patient\n2. Serve Patient\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(p.name, sizeof(p.name), stdin);
                p.name[strcspn(p.name, "\n")] = 0;
                printf("Enter Age: ");
                scanf("%d", &p.age);
                printf("Enter Priority (1=High, 2=Medium, 3=Low): ");
                scanf("%d", &p.priority);
                enqueue(p);
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
