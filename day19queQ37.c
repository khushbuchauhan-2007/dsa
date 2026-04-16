#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
    int n, arr[N];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min_sum = 2147483647; 
    int pair1 = 0, pair2 = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                pair1 = arr[i];
                pair2 = arr[j];
            }
        }
    }
    
    printf("The pair of elements whose sum is closest to zero is: %d %d\n", pair1, pair2);
    
    return 0;
}