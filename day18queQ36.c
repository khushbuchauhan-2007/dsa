#include <stdio.h>
#include <stdlib.h>
#define N 100
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));
    int left_product = 1;
    int right_product = 1;

    for (int i = 0; i < numsSize; i++) {
        answer[i] = left_product;
        left_product *= nums[i];
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= right_product;
        right_product *= nums[i];
    }

    *returnSize = numsSize;
    return answer;   
}

int main() {
    int n, nums[N], returnSize;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int* result = productExceptSelf(nums, n, &returnSize);
    
    printf("The product of all elements except self is: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    return 0;
}