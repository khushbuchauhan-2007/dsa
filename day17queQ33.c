#include <stdio.h>
#define N 100
int main() {
    int n, arr[N], max, min;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    max = arr[0];
    min = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    
    return 0;
}