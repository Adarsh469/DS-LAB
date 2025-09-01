#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Append node at end
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Interleave two lists into one
Node* interleave(Node* list1, Node* list2) {
    Node* head = NULL;
    Node* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        // Take from list1
        if (head == NULL) {
            head = list1;
            tail = head;
            list1 = list1->next;
        } else {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }

        // Take from list2
        tail->next = list2;
        tail = tail->next;
        list2 = list2->next;
    }

    // Attach remaining nodes
    if (list1 != NULL) tail->next = list1;
    if (list2 != NULL) tail->next = list2;

    return head;
}

// Print list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Free list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *list1 = NULL, *list2 = NULL, *list3 = NULL;
    int n1, n2, val;

    printf("Enter number of nodes in list1: ");
    scanf("%d", &n1);
    printf("Enter elements of list1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        append(&list1, val);
    }

    printf("Enter number of nodes in list2: ");
    scanf("%d", &n2);
    printf("Enter elements of list2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        append(&list2, val);
    }

    printf("\nList1: ");
    printList(list1);
    printf("List2: ");
    printList(list2);

    list3 = interleave(list1, list2);

    printf("\nInterleaved List3: ");
    printList(list3);

    freeList(list3);
    return 0;
}
