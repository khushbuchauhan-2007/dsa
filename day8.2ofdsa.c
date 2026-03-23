#include <stdio.h>
#include <stdbool.h>
bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false; 
    }
    return (n & (n - 1)) == 0;    
}
int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    
    if (isPowerOfTwo(n)) {
        printf("%d is a power of two.\n", n);
    } else {
        printf("%d is not a power of two.\n", n);
    }
    
    return 0;
}