#include <stdio.h>

int main() {
    int num[100], n, target;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    printf("Enter the target: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (num[i] + num[j] == target) {
                printf("Output: [%d, %d]\n", i, j);
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    if (found == 0) {
        printf("Not found\n");
    }

    return 0;
}
