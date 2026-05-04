/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

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
typedef struct {
    struct ListNode* top;
    struct ListNode* min;
} MinStack;
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = NULL;
    obj->min = NULL;
    return obj;
}
void minStackPush(MinStack* obj, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = obj->top;
    obj->top = newNode;

    if (obj->min == NULL || val <= obj->min->val) {
        struct ListNode* minNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        minNode->val = val;
        minNode->next = obj->min;
        obj->min = minNode;
    }
}
void minStackPop(MinStack* obj) {
    if (obj->top != NULL) {
        int popped = obj->top->val;
        struct ListNode* temp = obj->top;
        obj->top = obj->top->next;
        free(temp);

        if (obj->min != NULL && popped == obj->min->val) {
            struct ListNode* minTemp = obj->min;
            obj->min = obj->min->next;
            free(minTemp);
        }
    }
}
int minStackTop(MinStack* obj) {
    return obj->top->val;
}
int minStackGetMin(MinStack* obj) {
    return obj->min->val;
}
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    MinStack* stack = minStackCreate();
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token;
        } else if (token == '(') {
            minStackPush(stack, token);
        } else if (token == ')') {
            while (stack->top != NULL && stack->top->val != '(') {
                postfix[j++] = minStackTop(stack);
                minStackPop(stack);
            }
            minStackPop(stack); // Pop '('
        } else { // Operator
            while (stack->top != NULL && precedence(token) <= precedence(stack->top->val)) {
                postfix[j++] = minStackTop(stack);
                minStackPop(stack);
            }
            minStackPush(stack, token);
        }
    }

    while (stack->top != NULL) {
        postfix[j++] = minStackTop(stack);
        minStackPop(stack);
    }
    postfix[j] = '\0';
}
void minStackFree(MinStack* obj) {
    while (obj->top != NULL) {
        struct ListNode* temp = obj->top;
        obj->top = obj->top->next;
        free(temp);
    }
    while (obj->min != NULL) {
        struct ListNode* temp = obj->min;
        obj->min = obj->min->next;
        free(temp);
    }
    free(obj);
}
int main() {
    char infix[100];
    char postfix[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}