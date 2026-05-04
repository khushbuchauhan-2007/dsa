/*Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct {
    struct ListNode* stack1;
    struct ListNode* stack2;
} MyQueue;

void pushStack(struct ListNode** top, int x) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = x;
    newNode->next = *top;
    *top = newNode;
}

int popStack(struct ListNode** top) {
    struct ListNode* temp = *top;
    int val = temp->val;
    *top = temp->next;
    free(temp);
    return val;
}

int peekStack(struct ListNode* top) {
    return top->val;
}

bool isEmpty(struct ListNode* top) {
    return top == NULL;
}

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->stack1 = NULL;
    obj->stack2 = NULL;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    pushStack(&(obj->stack1), x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            pushStack(&(obj->stack2), popStack(&(obj->stack1)));
        }
    }
    return popStack(&(obj->stack2));
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->stack2)) {
        while (!isEmpty(obj->stack1)) {
            pushStack(&(obj->stack2), popStack(&(obj->stack1)));
        }
    }
    return peekStack(obj->stack2);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stack1) && isEmpty(obj->stack2);
}

void myQueueFree(MyQueue* obj) {
    while (!isEmpty(obj->stack1)) popStack(&(obj->stack1));
    while (!isEmpty(obj->stack2)) popStack(&(obj->stack2));
    free(obj);
}
int main() {
    MyQueue* myQueue = myQueueCreate();
    myQueuePush(myQueue, 1);
    myQueuePush(myQueue, 2);
    printf("Peek: %d\n", myQueuePeek(myQueue)); 
    printf("Pop: %d\n", myQueuePop(myQueue));   
    printf("Empty: %s\n", myQueueEmpty(myQueue) ? "true" : "false");
    myQueueFree(myQueue);
    return 0;
}