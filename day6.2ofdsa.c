#include <stdio.h>
#define N 100
int main() {
    int n, nums[N];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int non_zero_index = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[non_zero_index++] = nums[i];
        }
    }
    
    while (non_zero_index < n) {
        nums[non_zero_index++] = 0;
    }
    
    printf("Array after moving zeros to the end: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    return 0;
}