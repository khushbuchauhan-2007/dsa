#include <stdio.h>
#include <string.h>
#define N 100
int main() {
    char s[N];
    
    printf("Enter the string: ");
    scanf("%s", s);
    
    int left = 0;
    int right = strlen(s) - 1;
    int is_palindrome = 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            is_palindrome = 0; 
            break;
        }
        left++;
        right--;
    }
    
    if (is_palindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}