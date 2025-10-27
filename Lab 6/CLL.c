#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL, *last = NULL;

void insertEnd(int data);
void deleteBeginning();
void deleteEnd();
void display();

int main() {
    int choice, data;

    while (1) {
        printf("\n=== CIRCULAR SINGLY LINKED LIST ===\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(data);
                display();
                break;
            case 2:
                deleteBeginning();
                display();
                break;
            case 3:
                deleteEnd();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Insert at end using first and last pointers
void insertEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL) {
        first = last = newNode;
        last->next = first;  // circular link
    } else {
        last->next = newNode;
        last = newNode;
        last->next = first;
    }
    printf("Inserted %d successfully.\n", data);
}

// Delete from beginning
void deleteBeginning() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = first;

    if (first == last) {  // only one node
        first = last = NULL;
    } else {
        first = first->next;
        last->next = first;
    }

    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = first;

    if (first == last) {  // only one node
        printf("Deleted %d from end.\n", first->data);
        free(first);
        first = last = NULL;
        return;
    }

    // Traverse to second last node
    while (temp->next != last)
        temp = temp->next;

    printf("Deleted %d from end.\n", last->data);
    free(last);
    last = temp;
    last->next = first;
}

// Display circular list
void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = first;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}
