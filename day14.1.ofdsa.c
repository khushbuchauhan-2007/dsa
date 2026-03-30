#include <stdio.h>
#define N 100
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

    int is_identity = 1; // Assume it's an identity matrix until proven otherwise

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1) {
                is_identity = 0; // Diagonal element is not 1
                break;
            } else if (i != j && matrix[i][j] != 0) {
                is_identity = 0; // Non-diagonal element is not 0
                break;
            }
        }
        if (!is_identity) {
            break;
        }
    }

    if (is_identity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}