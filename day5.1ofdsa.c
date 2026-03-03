#include <stdio.h>

void merge_logs(int log1[], int n1, int log2[], int n2) {
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    
    while (i < n1) {
        printf("%d ", log1[i]);
        i++;
    }

    
    while (j < n2) {
        printf("%d ", log2[j]);
        j++;
    }
}

int main() {
    int log1[] = {1, 4, 7, 10};
    int log2[] = {2, 3, 8, 12};

    int n1 = sizeof(log1) / sizeof(log1[0]);
    int n2 = sizeof(log2) / sizeof(log2[0]);

    printf("Merged Logs: ");
    merge_logs(log1, n1, log2, n2);

    return 0;
}
  
