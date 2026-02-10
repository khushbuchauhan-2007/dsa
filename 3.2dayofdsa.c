#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int expected_sum, actual_sum = 0, missing;

    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n - 1);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        actual_sum += arr[i];
    }

    expected_sum = n * (n + 1) / 2;
    missing = expected_sum - actual_sum;

    printf("Missing element is: %d\n", missing);

    return 0;
}
