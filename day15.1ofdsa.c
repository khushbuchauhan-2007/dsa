#include <stdio.h>
#define N 100
int main() {
    int m, n, matrix[N][N], diagonal_sum = 0;
    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < m && i < n; i++) {
        diagonal_sum += matrix[i][i];
    }
    
    printf("Sum of primary diagonal elements: %d\n", diagonal_sum);
    
    return 0;
}