#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void fastTranspose(Element a[], Element b[]) {
    int row_terms[MAX], starting_pos[MAX];
    int num_cols = a[0].col;
    int num_terms = a[0].value;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if (num_terms > 0) {
        // Step 1: Initialize row_terms to 0
        for (int i = 0; i < num_cols; i++)
            row_terms[i] = 0;

        // Step 2: Count number of terms in each column of a
        for (int i = 1; i <= num_terms; i++)
            row_terms[a[i].col]++;

        // Step 3: Find starting position for each column in b
        starting_pos[0] = 1;
        for (int i = 1; i < num_cols; i++)
            starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

        // Step 4: Place elements at correct position in b
        for (int i = 1; i <= num_terms; i++) {
            int j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void printSparse(Element a[]) {
    int n = a[0].value;
    printf("\nRow\tCol\tVal\n");
    for (int i = 0; i <= n; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

int main() {
    int m, n, num;
    Element a[MAX], b[MAX];

    printf("Enter rows and cols of matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &num);

    a[0].row = m;
    a[0].col = n;
    a[0].value = num;

    printf("Enter row, col, value for each non-zero element:\n");
    for (int i = 1; i <= num; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    printf("\nOriginal Sparse Matrix (Triplet form):\n");
    printSparse(a);

    fastTranspose(a, b);

    printf("\nFast Transpose of Sparse Matrix:\n");
    printSparse(b);

    return 0;
}
