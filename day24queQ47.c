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
struct ListNode* deleteKey(struct ListNode* head, int key) {
    if (head == NULL) {
        return NULL;
    }
    
    if (head->val == key) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct ListNode* current = head;
    while (current->next != NULL) {
        if (current->next->val == key) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        }
        current = current->next;
    }
    
    return head;
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

    printf("Enter the key to delete: ");
    scanf("%d", &key);

    head = deleteKey(head, key);
    
    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}