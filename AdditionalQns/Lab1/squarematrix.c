#include <stdio.h>

// Function to check if a matrix is a magic square
int isMagicSquare(int n, int M[n][n]) {
    int sum_diag1 = 0, sum_diag2 = 0;

    // Sum of first row as reference
    int target = 0;
    for (int j = 0; j < n; j++)
        target += M[0][j];

    // Check row sums
    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++)
            row_sum += M[i][j];
        if (row_sum != target)
            return 0;
    }

    // Check column sums
    for (int j = 0; j < n; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++)
            col_sum += M[i][j];
        if (col_sum != target)
            return 0;
    }

    // Check diagonals
    for (int i = 0; i < n; i++) {
        sum_diag1 += M[i][i];
        sum_diag2 += M[i][n - 1 - i];
    }
    if (sum_diag1 != target || sum_diag2 != target)
        return 0;

    return 1;
}

int main() {
    int m, n, p, q;

    // Input matrices A and B
    printf("Enter rows and cols of Matrix A: ");
    scanf("%d %d", &m, &n);

    int A[m][n];
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter rows and cols of Matrix B: ");
    scanf("%d %d", &p, &q);

    int B[p][q];
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            scanf("%d", &B[i][j]);

    // (i) Multiply A × B
    if (n == p) {
        int C[m][q];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        printf("\nMatrix Multiplication (A x B):\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
    } else {
        printf("\nMatrix multiplication not possible (columns of A != rows of B).\n");
    }

    // (ii) Add A + B
    if (m == p && n == q) {
        int D[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j] = A[i][j] + B[i][j];
            }
        }
        printf("\nMatrix Addition (A + B):\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", D[i][j]);
            printf("\n");
        }
    } else {
        printf("\nMatrix addition not possible (different dimensions).\n");
    }

    // (iii) Magic Square Check
    int s;
    printf("\nEnter order of square matrix to check for Magic Square: ");
    scanf("%d", &s);

    int M[s][s];
    printf("Enter elements of the square matrix:\n");
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            scanf("%d", &M[i][j]);

    if (isMagicSquare(s, M))
        printf("The matrix is a Magic Square ✅\n");
    else
        printf("The matrix is NOT a Magic Square ❌\n");

    return 0;
}
