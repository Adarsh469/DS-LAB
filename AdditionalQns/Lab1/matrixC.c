#include <stdio.h>

int main() {
    int m, n;

    // Input dimensions
    printf("Enter rows and columns of the matrices: ");
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], C[m][n];

    // Input Matrix A
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input Matrix B
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Compute Matrix C
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];
        }
    }

    // Display Matrix C
    printf("Matrix C (max of A and B):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
