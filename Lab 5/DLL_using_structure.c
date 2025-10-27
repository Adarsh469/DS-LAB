#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;

void insertRear(int data);
void deleteRear();
void insertAtPosition(int data, int position);
void deleteAtPosition(int position);
void insertAfterValue(int data, int value);
void insertBeforeValue(int data, int value);
void traverseForward();
void traverseReverse();

int main() {
    int choice, data, position, value;

    while (1) {
        printf("\n==== DOUBLY LINKED LIST MENU ====\n");
        printf("1. Insert element at rear end\n");
        printf("2. Delete element from rear end\n");
        printf("3. Insert element at given position\n");
        printf("4. Delete element from given position\n");
        printf("5. Insert element after a given value\n");
        printf("6. Insert element before a given value\n");
        printf("7. Traverse forward\n");
        printf("8. Traverse reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertRear(data);
                break;

            case 2:
                deleteRear();
                break;

            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtPosition(data, position);
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;

            case 5:
                printf("Enter value after which to insert: ");
                scanf("%d", &value);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAfterValue(data, value);
                break;

            case 6:
                printf("Enter value before which to insert: ");
                scanf("%d", &value);
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeforeValue(data, value);
                break;

            case 7:
                traverseForward();
                break;

            case 8:
                traverseReverse();
                break;

            case 9:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Insert at rear
void insertRear(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    printf("Inserted %d at the rear.\n", data);
}

// 2. Delete from rear
void deleteRear() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = tail;
    printf("Deleted %d from the rear.\n", temp->data);

    if (head == tail) { // Only one node
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

// 3. Insert at a given position
void insertAtPosition(int data, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    if (position <= 0) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    if (position == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
        printf("Inserted %d at position %d.\n", data, position);
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", data, position);
}

// 4. Delete from a given position
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    printf("Deleted %d from position %d.\n", temp->data, position);

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
}

// 5. Insert after a specific value
void insertAfterValue(int data, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;

    printf("Inserted %d after %d.\n", data, value);
}

// 6. Insert before a specific value
void insertBeforeValue(int data, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    printf("Inserted %d before %d.\n", data, value);
}

// 7. Traverse forward
void traverseForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 8. Traverse reverse
void traverseReverse() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = tail;
    printf("List (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
