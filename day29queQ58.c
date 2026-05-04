/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    
    struct ListNode* current = dummyHead;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        current->next = newNode;
        current = current->next;
    }
    
    struct ListNode* resultHead = dummyHead->next;
    free(dummyHead);
    return resultHead;
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
    int n1, n2;
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d", &n1);
    
    struct ListNode* l1 = NULL;
    struct ListNode* tail1 = NULL;
    
    printf("Enter the elements of the first linked list: ");
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (l1 == NULL) {
            l1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = tail1->next;
        }
    }
    
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d", &n2);
    
    struct ListNode* l2 = NULL;
    struct ListNode* tail2 = NULL;
    
    printf("Enter the elements of the second linked list: ");
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (l2 == NULL) {
            l2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = tail2->next;
        }
    }
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    printf("Resultant linked list after addition: ");
    printList(result);
    
    return 0;
}