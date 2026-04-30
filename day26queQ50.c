/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            struct ListNode *entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    
    return NULL;    
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
    int n, pos;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    printf("Enter the linked list elements: ");
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
    
    printf("Enter the position to create a cycle (-1 for no cycle): ");
    scanf("%d", &pos);
    
    if (pos >= 0) {
        struct ListNode* cycleStart = head;
        for (int i = 0; i < pos; i++) {
            cycleStart = cycleStart->next;
        }
        tail->next = cycleStart;
    }
    
    struct ListNode* cycleNode = detectCycle(head);
    if (cycleNode != NULL) {
        printf("Cycle detected at node with value: %d\n", cycleNode->val);
    } else {
        printf("No cycle detected.\n");
    }
    
    return 0;
}