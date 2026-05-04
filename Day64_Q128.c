/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Pair;

typedef struct {
    Pair data[1000];
    int front, rear;
} Queue;

void enqueue(Queue *q, int x, int y) {
    q->data[++q->rear].x = x;
    q->data[q->rear].y = y;
}

Pair dequeue(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    Queue q;
    q.front = 0;
    q.rear = -1;

    int fresh = 0;
    int minutes = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                enqueue(&q, i, j);
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (!isEmpty(&q) && fresh > 0) {
        int size = q.rear - q.front + 1;
        int rottedThisMinute = 0;

        for (int i = 0; i < size; i++) {
            Pair p = dequeue(&q);

            for (int d = 0; d < 4; d++) {
                int nx = p.x + dir[d][0];
                int ny = p.y + dir[d][1];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    enqueue(&q, nx, ny);
                    fresh--;
                    rottedThisMinute = 1;
                }
            }
        }

        if (rottedThisMinute) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int** grid = (int**)malloc(rows * sizeof(int*));
    int* gridColSize = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        gridColSize[i] = cols;
    }

    printf("Enter grid values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, rows, gridColSize);

    printf("Output: %d\n", result);

    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);

    return 0;
}