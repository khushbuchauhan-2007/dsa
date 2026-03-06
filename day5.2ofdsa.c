#include <stdio.h>
#define N 100
int main() {
    int m, n, nums1[N], nums2[N];

    printf("Enter the number of elements in nums1 (m): ");
    scanf("%d", &m);

    printf("Enter the elements of nums1: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter the number of elements in nums2 (n): ");
    scanf("%d", &n);

    printf("Enter the elements of nums2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Merge nums2 into nums1
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}


