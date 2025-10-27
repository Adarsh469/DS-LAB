#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *X1_head = NULL;
struct Node *X1_tail = NULL;
struct Node *X2_head = NULL;
struct Node *X2_tail = NULL;

struct Node* createNode(int data);
void insertRear(struct Node **head, struct Node **tail, int data);
void displayList(struct Node *head);
void concatenate();

int main() {
    int choice, data;

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Insert into List X1\n");
        printf("2. Insert into List X2\n");
        printf("3. Display List X1\n");
        printf("4. Display List X2\n");
        printf("5. Concatenate X1 and X2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into X1: ");
                scanf("%d", &data);
                insertRear(&X1_head, &X1_tail, data);
                break;

            case 2:
                printf("Enter data to insert into X2: ");
                scanf("%d", &data);
                insertRear(&X2_head, &X2_tail, data);
                break;

            case 3:
                printf("List X1: ");
                displayList(X1_head);
                break;

            case 4:
                printf("List X2: ");
                displayList(X2_head);
                break;

            case 5:
                concatenate();
                printf("After concatenation, X1 = X1 + X2\n");
                printf("List X1 (Result): ");
                displayList(X1_head);
                printf("List X2 (Now empty): ");
                displayList(X2_head);
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Create a new node dynamically
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at rear of a list
void insertRear(struct Node **head, struct Node **tail, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
    printf("Inserted %d successfully.\n", data);
}

// Display list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Concatenate X2 to the end of X1
void concatenate() {
    if (X1_head == NULL && X2_head == NULL) {
        printf("Both lists are empty. Nothing to concatenate.\n");
        return;
    }

    if (X1_head == NULL) {
        // If X1 is empty, X1 becomes X2
        X1_head = X2_head;
        X1_tail = X2_tail;
    } else if (X2_head != NULL) {
        // If both lists are non-empty
        X1_tail->next = X2_head;
        X2_head->prev = X1_tail;
        X1_tail = X2_tail;
    }

    // Make X2 empty
    X2_head = X2_tail = NULL;
    printf("Concatenation successful!\n");
}
