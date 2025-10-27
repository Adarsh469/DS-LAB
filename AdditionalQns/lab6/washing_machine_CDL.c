#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

struct User {
    char name[50];
    int time; // in seconds
    struct User *next, *prev;
};

struct User *head = NULL;

void addUser(char name[], int time);
void simulateQueue();
void displayQueue();

int main() {
    int choice, time;
    char name[50];

    while (1) {
        printf("\n=== Washing Machine Rental System ===\n");
        printf("1. Add User\n");
        printf("2. Display Queue\n");
        printf("3. Simulate Usage\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter user name: ");
                scanf("%s", name);
                printf("Enter usage time (in seconds): ");
                scanf("%d", &time);
                addUser(name, time);
                break;

            case 2:
                displayQueue();
                break;

            case 3:
                simulateQueue();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
void addUser(char name[], int time) {
    struct User *newUser = (struct User*)malloc(sizeof(struct User));
    newUser->time = time;
    newUser->next = newUser->prev = NULL;
    strcpy(newUser->name, name);

    if (head == NULL) {
        head = newUser;
        head->next = head->prev = head;
    } else {
        struct User *tail = head->prev;
        tail->next = newUser;
        newUser->prev = tail;
        newUser->next = head;
        head->prev = newUser;
    }
    printf("User %s added successfully.\n", name);
}

void displayQueue() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct User *temp = head;
    printf("Current Queue: ");
    do {
        printf("[%s | %ds] ", temp->name, temp->time);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void simulateQueue() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct User *current = head;
    while (1) {
        printf("\nWashing machine in use by: %s for %d seconds\n", current->name, current->time);
        sleep(current->time);
        printf("Time over! Passing machine to next user...\n");
        current = current->next;
    }
}
