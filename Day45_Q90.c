/*Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}
int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    
    struct TreeNode* nodes[100]; // max nodes = 100
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (val != -1) {
            nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[i]->val = val;
            nodes[i]->left = NULL;
            nodes[i]->right = NULL;
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
    
    int result = maxDepth(nodes[0]);
    printf("%d\n", result);
    
    return 0;
}   
