/*Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    result[*index] = root->val;
    (*index)++;

    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(100 * sizeof(int)); // max nodes = 100
    int index = 0;

    preorder(root, result, &index);

    *returnSize = index;
    return result;
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
            int leftIndex, rightIndex;
            scanf("%d %d", &leftIndex, &rightIndex);
            if (leftIndex != -1) {
                nodes[i]->left = nodes[leftIndex];
            }
            if (rightIndex != -1) {
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }
    
    int returnSize;
    int* result = preorderTraversal(nodes[0], &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    return 0;
}