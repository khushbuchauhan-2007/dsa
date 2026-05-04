/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

 

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
 

Constraints:
1 ≤ V ≤ 105*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int timer;

void dfs(int u, int parent, int visited[], int tin[], int low[], int ap[], int **adj, int *size) {
    visited[u] = 1;
    tin[u] = low[u] = timer++;
    int children = 0;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (visited[v]) {
            if (low[u] > tin[v]) low[u] = tin[v];
        } else {
            dfs(v, u, visited, tin, low, ap, adj, size);

            if (low[u] > low[v]) low[u] = low[v];

            if (low[v] >= tin[u] && parent != -1)
                ap[u] = 1;

            children++;
        }
    }

    if (parent == -1 && children > 1)
        ap[u] = 1;
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = (int**)malloc(V * sizeof(int*));
    int *size = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(MAX * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int visited[MAX] = {0};
    int tin[MAX], low[MAX], ap[MAX] = {0};

    timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, -1, visited, tin, low, ap, adj, size);
    }

    int res[MAX];
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            res[count++] = i;
        }
    }

    if (count == 0) {
        printf("-1");
    } else {
        qsort(res, count, sizeof(int), cmp);
        for (int i = 0; i < count; i++) {
            printf("%d ", res[i]);
        }
    }

    return 0;
}