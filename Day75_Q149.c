/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>
#include <stdlib.h>

int longestZeroSumSubarray(int arr[], int n) {
    int *hash = (int *)malloc(sizeof(int) * (2 * n + 1));
    for (int i = 0; i < 2 * n + 1; i++)
        hash[i] = -2;

    int offset = n;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        if (hash[sum + offset] != -2) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + offset] = i;
        }
    }

    free(hash);
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", longestZeroSumSubarray(arr, n));
    return 0;
}