/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length*/

#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {

    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int *deque = (int*)malloc(sizeof(int) * numsSize);

    int front = 0, rear = -1;
    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++) {

        if (front <= rear && deque[front] <= i - k)
            front++;

        while (front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        deque[++rear] = i;

        if (i >= k - 1)
            result[i - k + 1] = nums[deque[front]];
    }

    free(deque);
    return result;
}

int main() {

    int nums[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    int returnSize;

    int* result = maxSlidingWindow(nums, numsSize, k, &returnSize);

    for(int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    free(result);

    return 0;
}