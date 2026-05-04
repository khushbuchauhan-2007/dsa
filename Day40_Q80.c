/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {

    int *ans = (int*)malloc(sizeof(int) * temperaturesSize);
    int *stack = (int*)malloc(sizeof(int) * temperaturesSize);
    
    memset(ans, 0, sizeof(int) * temperaturesSize);

    int top = -1;

    for(int i = 0; i < temperaturesSize; i++) {

        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }

        stack[++top] = i;
    }

    *returnSize = temperaturesSize;

    free(stack);
    return ans;
}
int main() {
    int temperatures[] = {73,74,75,71,69,72,76,73};
    int temperaturesSize = sizeof(temperatures) / sizeof(temperatures[0]);
    int returnSize;

    int* result = dailyTemperatures(temperatures, temperaturesSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);
    return 0;
}