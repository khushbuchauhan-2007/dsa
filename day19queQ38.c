#include <stdio.h>
#include <stdlib.h>
#define N 100
int maxSubarraySumCircular(int* nums, int numsSize) {
    int max_sum = nums[0];
    int current_max = nums[0];
    int min_sum = nums[0];
    int current_min = nums[0];
    int total_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        total_sum += nums[i];
        
        current_max = (current_max > 0) ? current_max + nums[i] : nums[i];
        max_sum = (max_sum > current_max) ? max_sum : current_max;
        
        current_min = (current_min < 0) ? current_min + nums[i] : nums[i];
        min_sum = (min_sum < current_min) ? min_sum : current_min;
    }

    return (max_sum > 0) ? ((total_sum - min_sum > max_sum) ? total_sum - min_sum : max_sum) : max_sum;   
}

int main() {
    int n, nums[N];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);
    
    printf("The maximum possible sum of a non-empty subarray is: %d\n", result);
    
    return 0;
}