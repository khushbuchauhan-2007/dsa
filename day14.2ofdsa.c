#include <stdio.h>
#define N 20
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = i; j < matrixSize - i - 1; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = temp;
        }
    }   
}
int main() {
    int n, matrix[N][N];
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotate((int**)matrix, n, NULL);

    printf("Rotated Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}