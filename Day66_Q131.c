/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int dfs(int node, int V, int adj[MAX][MAX], int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1) {
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return 1;
            }
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0;
    return 0;
}

int isCycle(int V, int adj[MAX][MAX]) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}