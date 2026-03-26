#include <stdio.h>
#include <stdbool.h>
#define N 100
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize - 1; i++) {
        for (int j = 0; j < matrixColSize[0] - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false;
            }
        }
    }
    return true;
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
    
    if (isToeplitzMatrix((int**)matrix, m, (int[]){n})) {
        printf("The matrix is a Toeplitz Matrix\n");
    } else {
        printf("The matrix is not a Toeplitz Matrix\n");
    }
    
    return 0;
}