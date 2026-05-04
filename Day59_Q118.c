/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* solve(int* inorder, int* postorder, int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(curr);

    if (start == end)
        return root;

    int pos = findIndex(inorder, start, end, curr);

    root->right = solve(inorder, postorder, pos + 1, end, postIndex);
    root->left = solve(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return solve(inorder, postorder, 0, inorderSize - 1, &postIndex);
}

void printPreorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

void printPostorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    printPreorder(root);

    free(inorder);
    free(postorder);

    return 0;
}