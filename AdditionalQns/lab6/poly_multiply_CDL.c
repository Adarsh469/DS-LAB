#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *prev, *next;
};

// Create header node
struct Node* createHeader() {
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->next = head->prev = head;
    head->coeff = 0;
    head->exp = -1;
    return head;
}

// Insert term (in descending order)
void insertTerm(struct Node *head, int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;

    struct Node *temp = head->next;
    while (temp != head && temp->exp > exp)
        temp = temp->next;

    if (temp != head && temp->exp == exp) {
        temp->coeff += coeff; // Merge same exponent
        free(newNode);
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

// Display polynomial
void displayPoly(struct Node *head) {
    struct Node *temp = head->next;
    if (temp == head) {
        printf("0\n");
        return;
    }

    while (temp != head) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != head)
            printf(" + ");
    }
    printf("\n");
}

// Multiply polynomials
struct Node* multiply(struct Node *P1, struct Node *P2) {
    struct Node *result = createHeader();

    for (struct Node *t1 = P1->next; t1 != P1; t1 = t1->next) {
        for (struct Node *t2 = P2->next; t2 != P2; t2 = t2->next) {
            int coeff = t1->coeff * t2->coeff;
            int exp = t1->exp + t2->exp;
            insertTerm(result, coeff, exp);
        }
    }
    return result;
}

int main() {
    struct Node *P1 = createHeader();
    struct Node *P2 = createHeader();

    int n1, n2, coeff, exp;
    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coeff and exp: ");
        scanf("%d%d", &coeff, &exp);
        insertTerm(P1, coeff, exp);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coeff and exp: ");
        scanf("%d%d", &coeff, &exp);
        insertTerm(P2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPoly(P1);
    printf("Polynomial 2: ");
    displayPoly(P2);

    struct Node *Product = multiply(P1, P2);
    printf("Result (Product): ");
    displayPoly(Product);

    return 0;
}
