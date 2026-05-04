/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

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

    MinStack* minStack = minStackCreate();

    minStackPush(minStack, -2);
    minStackPush(minStack, 0);
    minStackPush(minStack, -3);

    printf("Minimum element: %d\n", minStackGetMin(minStack));

    minStackPop(minStack);

    printf("Top element: %d\n", minStackTop(minStack));
    printf("Minimum element: %d\n", minStackGetMin(minStack));

    minStackFree(minStack);

    return 0;
}