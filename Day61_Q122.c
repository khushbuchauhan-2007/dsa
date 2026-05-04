/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int** isConnected, int n, int city, int* visited) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && visited[i] == 0) {
            dfs(isConnected, n, i, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(isConnected, n, i, visited);
            provinces++;
        }
    }

    free(visited);
    return provinces;
}

int main() {
    int n;
    scanf("%d", &n);

    int** isConnected = (int**)malloc(n * sizeof(int*));
    int* isConnectedColSize = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        isConnected[i] = (int*)malloc(n * sizeof(int));
        isConnectedColSize[i] = n;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int result = findCircleNum(isConnected, n, isConnectedColSize);
    printf("%d\n", result);

    for (int i = 0; i < n; i++) {
        free(isConnected[i]);
    }
    free(isConnected);
    free(isConnectedColSize);

    return 0;
}