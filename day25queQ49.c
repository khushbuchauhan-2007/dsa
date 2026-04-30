/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/

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
int countOccurrences(struct ListNode* head, int key) {
    int count = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        if (current->val == key) {
            count++;
        }
        current = current->next;
    }
    return count;
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
    int n, key;
    printf("Enter the number of nodes: ");
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
    
    printf("Enter the key to count: ");
    scanf("%d", &key);
    
    int occurrences = countOccurrences(head, key);
    printf("Number of occurrences of %d: %d\n", key, occurrences);
    
    return 0;
}