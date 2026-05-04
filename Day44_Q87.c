/*Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL)
        return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}
void preorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL)
        return;

    arr[(*index)++] = root->val;
    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}
void postorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL)
        return;

    postorder(root->left, arr, index);
    postorder(root->right, arr, index);
    arr[(*index)++] = root->val;
}
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main() {
    int n;
    scanf("%d", &n);
    
    struct TreeNode* nodes[n];
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (val != -1) {
            nodes[i] = createNode(val);
        } else {
            nodes[i] = NULL;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n) {
                nodes[i]->left = nodes[leftIndex];
            }
            if (rightIndex < n) {
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }
    
    int inorderArr[n], preorderArr[n], postorderArr[n];
    int inorderIndex = 0, preorderIndex = 0, postorderIndex = 0;
    
    inorder(nodes[0], inorderArr, &inorderIndex);
    preorder(nodes[0], preorderArr, &preorderIndex);
    postorder(nodes[0], postorderArr, &postorderIndex);
    
    for (int i = 0; i < inorderIndex; i++) {
        printf("%d ", inorderArr[i]);
    }
    printf("\n");
    
    for (int i = 0; i < preorderIndex; i++) {
        printf("%d ", preorderArr[i]);
    }
    printf("\n");
    
    for (int i = 0; i < postorderIndex; i++) {
        printf("%d ", postorderArr[i]);
    }
    printf("\n");
    
    return 0;
}
