/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>
#include <stdlib.h>
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
struct Stack {
    struct ListNode* top;
};
void push(struct Stack* stack, int val) {
    struct ListNode* newNode = createNode(val);
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return -1; 
    }
    struct ListNode* temp = stack->top;
    int val = temp->val;
    stack->top = stack->top->next;
    free(temp);
    return val;
}
void printStack(struct Stack* stack) {
    struct ListNode* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}   
int main() {
    struct Stack stack;
    stack.top = NULL;
    
    int n, m;
    printf("Enter the number of elements to push: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int val;
        printf("Enter value to push: ");
        scanf("%d", &val);
        push(&stack, val);
    }
    
    printf("Enter the number of elements to pop: ");
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        pop(&stack);
    }
    
    printStack(&stack);
    
    return 0;
}