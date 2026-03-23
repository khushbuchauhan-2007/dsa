#include <stdio.h>
#define N 100
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;
        right--;
    }   
}
int main() {
    char s[N];
    
    printf("Enter the string to reverse: ");
    scanf("%s", s);
    
    int sSize = 0;
    while (s[sSize] != '\0') {
        sSize++;
    }
    
    reverseString(s, sSize);
    
    printf("Reversed string: %s\n", s);
    
    return 0;
}