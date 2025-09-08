#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert a term at the end of polynomial
struct Node* insertEnd(struct Node* head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Display polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            result = insertEnd(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            result = insertEnd(result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            result = insertEnd(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertEnd(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertEnd(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

// Multiply two polynomials
struct Node* multiplyPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    for (struct Node* i = p1; i != NULL; i = i->next) {
        for (struct Node* j = p2; j != NULL; j = j->next) {
            int coeff = i->coeff * j->coeff;
            int pow = i->pow + j->pow;

            // Insert in sorted order (merge like terms)
            struct Node* temp = result, *prev = NULL;
            while (temp != NULL && temp->pow > pow) {
                prev = temp;
                temp = temp->next;
            }
            if (temp != NULL && temp->pow == pow) {
                temp->coeff += coeff;
            } else {
                struct Node* newNode = createNode(coeff, pow);
                if (prev == NULL) { // insert at beginning
                    newNode->next = result;
                    result = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }
        }
    }
    return result;
}

// Differentiate polynomial
struct Node* differentiate(struct Node* head) {
    struct Node* result = NULL;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->pow != 0) {
            result = insertEnd(result, temp->coeff * temp->pow, temp->pow - 1);
        }
        temp = temp->next;
    }
    return result;
}

// Evaluate polynomial for given x
int evaluate(struct Node* head, int x) {
    int result = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        int term = 1;
        for (int i = 0; i < temp->pow; i++) term *= x;
        result += temp->coeff * term;
        temp = temp->next;
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Polynomial 1: 5x^2 + 4x^1 + 2
    poly1 = insertEnd(poly1, 5, 2);
    poly1 = insertEnd(poly1, 4, 1);
    poly1 = insertEnd(poly1, 2, 0);

    // Polynomial 2: 3x^3 + 2x^1 + 1
    poly2 = insertEnd(poly2, 3, 3);
    poly2 = insertEnd(poly2, 2, 1);
    poly2 = insertEnd(poly2, 1, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    // Addition
    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);

    // Multiplication
    struct Node* product = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    display(product);

    // Differentiation
    struct Node* diff = differentiate(poly1);
    printf("Derivative of Polynomial 1: ");
    display(diff);

    // Evaluation
    int x = 2;
    int value = evaluate(poly1, x);
    printf("Value of Polynomial 1 at x=%d: %d\n", x, value);

    return 0;
}
