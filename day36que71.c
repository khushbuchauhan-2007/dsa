/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

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

void printList(struct ListNode* front) {
    struct ListNode* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int main() {
    int n, m;

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    struct ListNode* front = NULL;
    struct ListNode* rear = NULL;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    printf("Enter the number of dequeue operations: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (front != NULL) {
            struct ListNode* temp = front;
            front = front->next;
            free(temp);

            if (front == NULL)
                rear = NULL;
        }
    }

    printf("Queue elements from front to rear after operations: ");
    printList(front);

    return 0;
}