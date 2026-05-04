/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
int evalRPN(char **tokens, int tokensSize) {
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *token = tokens[i];

        if (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];
            int result;

            if (strcmp(token, "+") == 0)
                result = a + b;
            else if (strcmp(token, "-") == 0)
                result = a - b;
            else if (strcmp(token, "*") == 0)
                result = a * b;
            else
                result = a / b;

            stack[++top] = result;
        } else {
            stack[++top] = atoi(token);
        }
    }

    return stack[top];
}
int main() {
    char *tokens[] = {"2", "3", "1", "*", "+", "9", "-"};
    int tokensSize = sizeof(tokens) / sizeof(tokens[0]);
    
    int result = evalRPN(tokens, tokensSize);
    printf("%d\n", result);
    
    return 0;
}