#include <stdio.h>
#define N 100
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
    
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }
    
    printf("Symmetric Matrix\n");
    return 0;
}