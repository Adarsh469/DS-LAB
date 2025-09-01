#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node (only for initial list creation)
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end of the list
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Merge two sorted lists (X and Y) into Z
Node* mergeLists(Node* X, Node* Y) {
    if (X == NULL) return Y;
    if (Y == NULL) return X;

    Node* Z = NULL;
    Node* tail = NULL;

    // Initialize head of merged list
    if (X->data <= Y->data) {
        Z = X;
        X = X->next;
    } else {
        Z = Y;
        Y = Y->next;
    }
    tail = Z;

    // Merge remaining nodes
    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            tail->next = X;
            X = X->next;
        } else {
            tail->next = Y;
            Y = Y->next;
        }
        tail = tail->next;
    }

    // Attach remaining part
    if (X != NULL) tail->next = X;
    if (Y != NULL) tail->next = Y;

    return Z; // Z is the merged list
}

// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Free memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *X = NULL, *Y = NULL, *Z = NULL;

    int n1, n2, val;

    printf("Enter number of nodes in list X: ");
    scanf("%d", &n1);
    printf("Enter elements of X in sorted order:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        append(&X, val);
    }

    printf("Enter number of nodes in list Y: ");
    scanf("%d", &n2);
    printf("Enter elements of Y in sorted order:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        append(&Y, val);
    }

    printf("\nList X: ");
    printList(X);
    printf("List Y: ");
    printList(Y);

    Z = mergeLists(X, Y);

    printf("\nMerged List Z: ");
    printList(Z);

    freeList(Z); // cleanup
    return 0;
}
