/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* leftSubtree = root->left;
    struct TreeNode* rightSubtree = root->right;

    root->left = NULL;
    root->right = leftSubtree;

    struct TreeNode* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }

    curr->right = rightSubtree;
}

void printFlattenedList(struct TreeNode* root) {
    struct TreeNode* curr = root;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->right;
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(6);

    flatten(root);

    printFlattenedList(root);

    return 0;
}