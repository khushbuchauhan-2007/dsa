#include <stdio.h>
#define N 200
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int row_zero[N] = {0};
    int col_zero[N] = {0};

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == 0) {
                row_zero[i] = 1;
                col_zero[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (row_zero[i] == 1 || col_zero[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }   
}

int main() {
    int m, n, matrix[N][N];
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    setZeroes((int**)matrix, m, (int[]){n});

    printf("Matrix after setting zeroes:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}