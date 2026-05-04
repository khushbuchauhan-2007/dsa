/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1005

int n, m;
int adj[MAX][MAX];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INT_MAX;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[MAX];
    bool inMST[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    key[1] = 0;

    int total = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (!inMST[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        inMST[u] = true;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INT_MAX && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d", total);
    return 0;
}