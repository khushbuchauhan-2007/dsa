#include <stdio.h>
#include <stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    int index = 0;
    int top = 0, bottom = matrixSize - 1, left = 0, right = (*matrixColSize) - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = index;
    return result;   
}
int main() {
    int r, c;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int* result = spiralOrder(matrix, r, &c, &returnSize);

    printf("Spiral traversal of the matrix: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}