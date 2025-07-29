#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int rows, int cols) {
    int **mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}
void freeMatrix(int **mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}
void readMatrix(int **mat, int rows, int cols) {
    printf("Enter elements of matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", * (mat + i) + j);
        }
    }
}
void displayMatrix(int **mat, int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
int** multiplyMatrices(int **mat1, int r1, int c1, int **mat2, int r2, int c2) {
    if (c1 != r2) {
        printf("Error: matrices cannot be multiplied due to dimension mismatch.\n");
        return NULL;
    }
    int **result = allocateMatrix(r1, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(*(result + i) + j) = 0;
            for (int k = 0; k < c1; k++) {
                *(*(result + i) + j) += (*(*(mat1 + i) + k)) * (*(*(mat2 + k) + j));
            }
        }
    }
    return result;
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);
    int **mat1 = allocateMatrix(r1, c1);
    int **mat2 = allocateMatrix(r2, c2);
    readMatrix(mat1, r1, c1);
    readMatrix(mat2, r2, c2);
    printf("First Matrix:\n");
    displayMatrix(mat1, r1, c1);

    printf("Second Matrix:\n");
    displayMatrix(mat2, r2, c2);

    int **product = multiplyMatrices(mat1, r1, c1, mat2, r2, c2);

    if (product != NULL) {
        printf("Product Matrix:\n");
        displayMatrix(product, r1, c2);
        freeMatrix(product, r1);
    }

    freeMatrix(mat1, r1);
    freeMatrix(mat2, r2);

    return 0;
}

