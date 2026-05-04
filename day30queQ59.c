/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int coeff;
    int exp;
    struct ListNode* next;
};
struct ListNode* createNode(int coeff, int exp) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void printPolynomial(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        if (current->coeff != 0) {
            if (current->exp == 0) {
                printf("%d", current->coeff);
            } else if (current->exp == 1) {
                printf("%dx", current->coeff);
            } else {
                printf("%dx^%d", current->coeff, current->exp);
            }
            if (current->next != NULL && current->next->coeff > 0) {
                printf(" + ");
            }
        }
        current = current->next;
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    
    printf("Enter the coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        struct ListNode* newNode = createNode(coeff, exp);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    printf("Polynomial: ");
    printPolynomial(head);
    
    return 0;
}