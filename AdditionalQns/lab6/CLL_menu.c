#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Function prototypes
struct Node* createNode(int data);
void insertElement(int data);
void deleteElement(int data);
void displayList();

int main() {
    int choice, data;

    while (1) {
        printf("\n=== Circular Doubly Linked List Menu ===\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertElement(data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteElement(data);
                break;

            case 3:
                displayList();
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

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert element at end
void insertElement(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node *tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("%d inserted successfully.\n", data);
}

// Delete element by value
void deleteElement(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    do {
        if (temp->data == data) {
            if (temp->next == temp) {
                head = NULL;  // single node case
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
            }
            free(temp);
            printf("%d deleted successfully.\n", data);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("%d not found in the list.\n", data);
}

// Display all nodes
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
