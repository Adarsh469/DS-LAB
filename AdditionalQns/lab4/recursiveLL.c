#include <stdio.h>
#include <stdlib.h>

// Define node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Recursive function to create a linked list
Node* createList(int n) {
    if (n == 0) return NULL;

    int value;
    printf("Enter data for node: ");
    scanf("%d", &value);

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    // Recursively create the rest of the list
    newNode->next = createList(n - 1);
    return newNode;
}

// Recursive function to traverse linked list
void traverse(Node *head) {
    if (head == NULL) return;

    printf("%d -> ", head->data);
    traverse(head->next);  // recursive call
}

// Recursive function to free memory
void freeList(Node *head) {
    if (head == NULL) return;
    freeList(head->next);
    free(head);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    Node *head = createList(n);

    printf("\nLinked List (Recursive Traversal):\n");
    traverse(head);
    printf("NULL\n");

    freeList(head); // cleanup
    return 0;
}
