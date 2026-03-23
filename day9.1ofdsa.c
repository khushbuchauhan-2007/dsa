#include <stdio.h>
#include <string.h>
#define N 100
int main() {
    char code_name[N];
    
    printf("Enter the code name: ");
    scanf("%s", code_name);
    
    int length = strlen(code_name);
    
    // Mirror the code name
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", code_name[i]);
    }
    printf("\n");
    
    return 0;
}