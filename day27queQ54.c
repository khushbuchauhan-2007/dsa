/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105*/

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
    
    struct ListNode* cycleStart = slow;
    struct ListNode* current = cycleStart;
    while (current->next != cycleStart) {
        current = current->next;
    }
    
    current->next = NULL; 
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
            tail = newNode;
        }
    }
    
    printf("Enter the position to create a cycle (0-based index): ");
    scanf("%d", &pos);
    
    if (pos >= 0 && pos < n) {
        struct ListNode* cycleStart = head;
        for (int i = 0; i < pos; i++) {
            cycleStart = cycleStart->next;
        }
        tail->next = cycleStart; 
    }
    
    int result = removeCycle(head);
    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}