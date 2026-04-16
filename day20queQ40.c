#include <stdio.h>
#include <stdlib.h>
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 1000); 
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000); 
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    int* triplet = (int*)malloc(sizeof(int) * 3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[j];
                    triplet[2] = nums[k];
                    result[*returnSize] = triplet;
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                }
            }
        }
    }

    return result;
}

int main() {
    int n, nums[3000], returnSize;
    int* returnColumnSizes;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int** result = threeSum(nums, n, &returnSize, &returnColumnSizes);
    
    printf("The triplets that sum up to zero are:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]); // Free each triplet
    }
    
    free(result); // Free the result array
    free(returnColumnSizes); // Free the column sizes array
    
    return 0;
}