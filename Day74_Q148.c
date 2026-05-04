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

void dfs(int i, int n, int isConnected[n][n], int visited[]) {
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(j, n, isConnected, visited);
        }
    }
}

int findCircleNum(int n, int isConnected[n][n]) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, isConnected, visited);
            provinces++;
        }
    }

    return provinces;
}

int main() {
    int n;
    scanf("%d", &n);

    int isConnected[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    printf("%d", findCircleNum(n, isConnected));

    return 0;
}