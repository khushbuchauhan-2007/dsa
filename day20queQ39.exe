#include <stdio.h>
#define N 100
int countZeroSumSubarrays(int* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, arr[N];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);
    printf("The count of subarrays having sum zero is: %d\n", result);
    
    return 0;
}