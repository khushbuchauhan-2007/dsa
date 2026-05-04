/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
bool isValid(char* s) {
    struct ListNode* stack = NULL;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        
        if (c == '(' || c == '{' || c == '[') {
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = c;
            newNode->next = stack;
            stack = newNode;
        } else {
            if (stack == NULL) {
                return false;
            }
            char top = stack->val;
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
            struct ListNode* temp = stack;
            stack = stack->next;
            free(temp);
        }
    }
    
    return stack == NULL;
}
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}
int main() {
    char s[100];
    printf("Enter a string of parentheses: ");
    scanf("%s", s);
    
    if (isValid(s)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }
    
    return 0;
}