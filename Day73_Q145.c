/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/

#include <stdio.h>
#include <string.h>

char firstNonRepeating(char str[]) {
    int freq[26] = {0};

    // Count frequency
    for(int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    // Find first non-repeating character
    for(int i = 0; str[i] != '\0'; i++) {
        if(freq[str[i] - 'a'] == 1) {
            return str[i];
        }
    }

    return '$';
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    char result = firstNonRepeating(str);

    printf("Output: %c\n", result);

    return 0;
}