/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/

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
int removeCycle(struct ListNode* head) {
    if (head == NULL) {
        return 0; 
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            break; 
        }
    }
    
    if (fast == NULL || fast->next == NULL) {
        return 0; 
    }
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return 1;
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
    int n, pos;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    
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
            tail = tail->next;
        }
    }
    
    printf("Enter the position to create a cycle (0 for no cycle): ");
    scanf("%d", &pos);
    
    if (pos > 0) {
        struct ListNode* current = head;
        for (int i = 1; i < pos && current != NULL; i++) {
            current = current->next;
        }
        if (current != NULL) {
            tail->next = current; 
        }
    }
    
    if (removeCycle(head)) {
        printf("Cycle removed successfully.\n");
    } else {
        printf("No cycle detected.\n");
    }
    
    printf("Linked list after removing cycle: ");
    printList(head);
    
    return 0;
}