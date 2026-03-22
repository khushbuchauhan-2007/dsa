#include <stdio.h>
#define N 100
int main() {
    int n, arr[N];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the sorted elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Unique elements in order: ");
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[