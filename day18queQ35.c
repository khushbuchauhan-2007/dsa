#include <stdio.h>
#define N 100
void rotate(int* arr, int n, int k) {
    k = k % n; 
    int temp[N];

    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    for (int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, arr[N], k;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);
    
    rotate(arr, n, k);
    
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}