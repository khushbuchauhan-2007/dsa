/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
 
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    struct Queue q;
    q.front = q.rear = 0;

    enqueue(&q, root);
    int level = 0;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;
        (*returnColumnSizes)[level] = size;

        result[level] = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);
            result[level][i] = node->val;

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        level++;
    }

    *returnSize = level;
    return result;
}
int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("[]\n");
        return 0;
    }

    struct TreeNode* nodes[2000];
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

    int returnSize;
    int* returnColumnSizes;
    int** result = levelOrder(nodes[0], &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(",");
        }
        printf("]");
        if (i < returnSize - 1) printf(",");
    }
    printf("]\n");
    return 0;
}
