#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data);
void insertRear(struct Node **head, struct Node **tail, int data);
void displayList(struct Node *head);
struct Node* addLongIntegers(struct Node *num1_tail, struct Node *num2_tail);

int main() {
    char str1[100], str2[100];
    struct Node *num1_head = NULL, *num1_tail = NULL;
    struct Node *num2_head = NULL, *num2_tail = NULL;
    struct Node *result_head = NULL;

    printf("Enter first long integer: ");
    scanf("%s", str1);
    printf("Enter second long integer: ");
    scanf("%s", str2);

    // Build list for num1
    for (int i = 0; str1[i] != '\0'; i++)
        insertRear(&num1_head, &num1_tail, str1[i] - '0');

    // Build list for num2
    for (int i = 0; str2[i] != '\0'; i++)
        insertRear(&num2_head, &num2_tail, str2[i] - '0');

    printf("\nNumber 1: ");
    displayList(num1_head);
    printf("Number 2: ");
    displayList(num2_head);

    result_head = addLongIntegers(num1_tail, num2_tail);

    printf("\nSum: ");
    displayList(result_head);

    return 0;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node **head, struct Node **tail, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL)
        *head = *tail = newNode;
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
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

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* addLongIntegers(struct Node *num1_tail, struct Node *num2_tail) {
    struct Node *res_head = NULL, *res_tail = NULL;
    int carry = 0;

    while (num1_tail != NULL || num2_tail != NULL || carry != 0) {
        int d1 = (num1_tail != NULL) ? num1_tail->data : 0;
        int d2 = (num2_tail != NULL) ? num2_tail->data : 0;
        int sum = d1 + d2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        // Insert at front to maintain order
        insertFront(&res_head, &res_tail, sum);

        if (num1_tail) num1_tail = num1_tail->prev;
        if (num2_tail) num2_tail = num2_tail->prev;
    }

    return res_head;
}
