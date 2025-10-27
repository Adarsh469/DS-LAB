#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data);
void insertRear(struct Node **head, struct Node **tail, int data);
int search(struct Node *head, int data);
void displayList(struct Node *head);
struct Node* unionList(struct Node *X1, struct Node *X2);
struct Node* intersectionList(struct Node *X1, struct Node *X2);

int main() {
    struct Node *X1_head = NULL, *X1_tail = NULL;
    struct Node *X2_head = NULL, *X2_tail = NULL;
    struct Node *Union = NULL, *Intersection = NULL;

    int n1, n2, data;
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertRear(&X1_head, &X1_tail, data);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertRear(&X2_head, &X2_tail, data);
    }

    printf("\nList 1: ");
    displayList(X1_head);
    printf("List 2: ");
    displayList(X2_head);

    Union = unionList(X1_head, X2_head);
    Intersection = intersectionList(X1_head, X2_head);

    printf("\nUnion: ");
    displayList(Union);
    printf("Intersection: ");
    displayList(Intersection);

    return 0;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertRear(struct Node **head, struct Node **tail, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL)
        *head = *tail = newNode;
    else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

int search(struct Node *head, int data) {
    while (head != NULL) {
        if (head->data == data)
            return 1;
        head = head->next;
    }
    return 0;
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* unionList(struct Node *X1, struct Node *X2) {
    struct Node *U_head = NULL, *U_tail = NULL;

    while (X1 != NULL) {
        if (!search(U_head, X1->data))
            insertRear(&U_head, &U_tail, X1->data);
        X1 = X1->next;
    }

    while (X2 != NULL) {
        if (!search(U_head, X2->data))
            insertRear(&U_head, &U_tail, X2->data);
        X2 = X2->next;
    }

    return U_head;
}
struct Node* intersectionList(struct Node *X1, struct Node *X2) {
    struct Node *I_head = NULL, *I_tail = NULL;

    while (X1 != NULL) {
        if (search(X2, X1->data) && !search(I_head, X1->data))
            insertRear(&I_head, &I_tail, X1->data);
        X1 = X1->next;
    }

    return I_head;
}
