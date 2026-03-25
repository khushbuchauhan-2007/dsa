#include <stdio.h>
#include <stdlib.h>
#define N 100
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(matrixColSize[0] * sizeof(int*));
    for (int i = 0; i < matrixColSize[0]; i++) {
        result[i] = (int*)malloc(matrixSize * sizeof(int));
    }
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    *returnSize = matrixColSize[0];
    *returnColumnSizes = (int*)malloc(matrixSize * sizeof(int));
    for (int i = 0; i < matrixSize; i++) {
        (*returnColumnSizes)[i] = matrixSize;
    }
    
    return result;
}
int main() {
    int m, n, matrix[N][N], result[N][N];
    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    printf("Transposed matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}