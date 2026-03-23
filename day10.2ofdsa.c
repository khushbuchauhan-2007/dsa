#include <stdio.h>
#define N 100
int main() {
    int n1, n2, nums1[N], nums2[N], intersection[N], k = 0;
    
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }
    
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (nums1[i] == nums2[j]) {
                intersection[k++] = nums1[i];
                nums2[j] = -1; 
                break;
            }
        }
    }
    
    printf("Intersection of the two arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", intersection[i]);
    }
    printf("\n");
    
    return 0;
}