#include <stdio.h>
#define N 100
int main() {
    int p, q, log1[N], log2[N];

    printf("Enter the number of entries in server log 1: ");
    scanf("%d", &p);

    printf("Enter the arrival times for server log 1: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter the number of entries in server log 2: ");
    scanf("%d", &q);

    printf("Enter the arrival times for server log 2: ");
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int i = 0, j = 0;
    printf("Merged arrival times in chronological order: ");
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    printf("\n");
    return 0;
}


