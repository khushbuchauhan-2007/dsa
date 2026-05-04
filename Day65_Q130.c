/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V*/

#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int parent, int **adj, int *visited, int *size) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited, size))
                return 1;
        } else if (neighbor != parent) {
            return 1;
        }
    }
    return 0;
}

int isCycle(int edges[][2], int E, int V) {
    int **adj = (int **)malloc(V * sizeof(int *));
    int *size = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        adj[i] = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int *visited = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited, size))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int edges[E][2];

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    if (isCycle(edges, E, V))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}