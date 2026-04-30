/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

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
struct ListNode* findIntersection(struct ListNode* headA, struct ListNode* headB) {
    int lenA = 0, lenB = 0;
    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;
    
    while (tempA != NULL) {
        lenA++;
        tempA = tempA->next;
    }
    
    while (tempB != NULL) {
        lenB++;
        tempB = tempB->next;
    }
    
    int diff = abs(lenA - lenB);
    if (lenA > lenB) {
        for (int i = 0; i < diff; i++) {
            headA = headA->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            headB = headB->next;
        }
    }
    
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA; 
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return NULL; 
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
    int n, m;
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d", &n);
    
    struct ListNode* headA = NULL;
    struct ListNode* tailA = NULL;

    printf("Enter the values of the first linked list: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (headA == NULL) {
            headA = newNode;
            tailA = newNode;
        } else {
            tailA->next = newNode;
            tailA = newNode;
        }
    }
    
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d", &m);
    
    struct ListNode* headB = NULL;
    struct ListNode* tailB = NULL;

    printf("Enter the values of the second linked list: ");
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (headB == NULL) {
            headB = newNode;
            tailB = newNode;
        } else {
            tailB->next = newNode;
            tailB = newNode;
        }
    }
    
    struct ListNode* intersection = findIntersection(headA, headB);
    if (intersection != NULL) {
        printf("Intersection at node with value: %d\n", intersection->val);
    } else {
        printf("No Intersection\n");
    }
    
    return 0;
}