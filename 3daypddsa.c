#include <stdio.h>

int main() {
    int arr[100], n, k;
    int i, comparisons = 0, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;          
        if (arr[i] == k) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Key %d found at position %d\n", k, i + 1); 
    } else {
        printf("Key %d not found in the array\n", k);
    }

    printf("Number of comparisons performed: %d\n", comparisons);

    return 0;
}
