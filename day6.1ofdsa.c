#include <stdio.h>
#define N 100

int main() {
    int n, arr[N];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n > N) {
        printf("Error: Maximum size is %d\n", N);
        return 1;
    }

    printf("Enter the sorted elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements in order: ");
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}