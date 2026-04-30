/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

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
struct ListNode* createCircularList(int n) {
    if (n <= 0) {
        return NULL;
    }
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    printf("Enter the values of the nodes: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    tail->next = head; 
    return head;
}
void printCircularList(struct ListNode* head) {
    if (head == NULL) {
        return;
    }
    
    struct ListNode* current = head;
    do {
        printf("%d ", current->val);
        current = current->next;
    } while (current != head);
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    
    struct ListNode* head = createCircularList(n);
    printCircularList(head);
    
    return 0;
}