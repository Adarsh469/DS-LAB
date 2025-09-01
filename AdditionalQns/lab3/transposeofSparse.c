#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void transpose(Element a[], Element b[]) {
    int n = a[0].value;  // number of non-zero elements
    int m = a[0].col;    // number of columns
    int q = 1;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    // For each column in original matrix
    for (int c = 0; c < m; c++) {
        for (int i = 1; i <= n; i++) {
            if (a[i].col == c) {
                b[q].row = a[i].col;
                b[q].col = a[i].row;
                b[q].value = a[i].value;
                q++;
            }
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

    transpose(a, b);

    printf("\nTranspose of Sparse Matrix:\n");
    printSparse(b);

    return 0;
}
