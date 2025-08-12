#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, int data, int ele, int pos) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    if (pos == 0) {
        if (head->data == ele) {
            newNode->next = head;
            return newNode;
        }
        Node* current = head;
        while (current->next != NULL && current->next->data != ele) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Element %d not found, inserting at end.\n", ele);
            current->next = newNode;
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
        return head;
    }

    else {
        Node* current = head;
        while (current != NULL && current->data != ele) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Element %d not found, inserting at end.\n", ele);
            current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
        return head;
    }
}

Node* delete(Node* head, int data, int alt) {
    if(alt == 0){
        if (head == NULL) {
            printf("Linked list is empty.\n");
            return NULL;
        }
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            printf("Element not found in the linked list.\n");
            return head;
        }
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Element deleted successfully.\n");
        return head;
    }
    else {
        if (head == NULL) {
            printf("Linked list is empty.\n");
            return NULL;
        }
        Node* current = head;

        while (current != NULL && current->next != NULL) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            current = current->next;
        }

        printf("Deleted every alternate node.\n");
        return head;
    }

}

void display(Node* head) {
    if (head == NULL){
        printf("Linked list is empty.\n");
        return;
    }
    Node* current = head;
    printf("Linked list elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* reverse(Node* head){
    if (head == NULL){
        printf("Linked list is empty.\n");
        return NULL;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* sort(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return NULL;
    }
    int swapped;
    Node* current = head;
    do {
        swapped = 0;
        current = head;
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
    return head;
}

Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL || data < head->data) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main(){
    Node* head = NULL;
    int choice, data, ele;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element before specified element\n");
        printf("2. Insert an element after specified element\n");
        printf("3. Delete an element from linked list\n");
        printf("4. Display the linked list\n");
        printf("5. Reverse the Linked List\n");
        printf("6. Sort Linked List\n");
        printf("7. Delete everyt alternating node\n");
        printf("8. Insert while maintatining the sorted structure\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which that element should be inserted: ");
                scanf("%d", &ele);
                head = insert(head, data, ele, 0);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which that element should be inserted: ");
                scanf("%d", &ele);
                head = insert(head, data, ele, 1);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                head = delete(head, data, 0);
                break;
            case 4:
                display(head);
                break;
            case 5:
                head = reverse(head);
                break;
            case 6:
                sort(head);
                break;
            case 7:
                delete(head, 0, 1);
                break;
            case 8:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertSorted(head, data);
                break;
            case 9:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
