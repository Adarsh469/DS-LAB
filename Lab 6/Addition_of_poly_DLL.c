#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term *prev;
    struct Term *next;
};

struct Term* createNode(int coeff, int exp);
void insertTerm(struct Term **head, struct Term **tail, int coeff, int exp);
void displayPolynomial(struct Term *head);
struct Term* addPolynomials(struct Term *poly1, struct Term *poly2);

int main() {
    struct Term *poly1_head = NULL, *poly1_tail = NULL;
    struct Term *poly2_head = NULL, *poly2_tail = NULL;
    struct Term *sum_head = NULL;

    int n1, n2, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms in descending order of exponents (coeff exp):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1_head, &poly1_tail, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms in descending order of exponents (coeff exp):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2_head, &poly2_tail, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1_head);
    printf("Polynomial 2: ");
    displayPolynomial(poly2_head);

    sum_head = addPolynomials(poly1_head, poly2_head);

    printf("\nSum Polynomial: ");
    displayPolynomial(sum_head);

    return 0;
}
struct Term* createNode(int coeff, int exp) {
    struct Term *newNode = (struct Term*)malloc(sizeof(struct Term));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertTerm(struct Term **head, struct Term **tail, int coeff, int exp) {
    struct Term *newNode = createNode(coeff, exp);
    if (*head == NULL)
        *head = *tail = newNode;
    else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Display polynomial
void displayPolynomial(struct Term *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct Term* addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result_head = NULL, *result_tail = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result_head, &result_tail, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly2->exp > poly1->exp) {
            insertTerm(&result_head, &result_tail, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else { // same exponent
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
                insertTerm(&result_head, &result_tail, sumCoeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        insertTerm(&result_head, &result_tail, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result_head, &result_tail, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result_head;
}
