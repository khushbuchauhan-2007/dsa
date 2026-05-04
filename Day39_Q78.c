/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    int freq;
} Node;

int cmp(const void *a, const void *b) {
    Node *x = (Node*)a;
    Node *y = (Node*)b;
    return y->freq - x->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    Node arr[numsSize];
    int unique = 0;

    for(int i = 0; i < numsSize; i++) {
        int found = 0;

        for(int j = 0; j < unique; j++) {
            if(arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found) {
            arr[unique].num = nums[i];
            arr[unique].freq = 1;
            unique++;
        }
    }

    qsort(arr, unique, sizeof(Node), cmp);

    int *result = (int*)malloc(sizeof(int) * k);

    for(int i = 0; i < k; i++) {
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}
int main() {
    int nums[] = {1,1,1,2,2,3};
    int k = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = topKFrequent(nums, numsSize, k, &returnSize);

    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}