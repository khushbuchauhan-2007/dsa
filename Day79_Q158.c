/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

Examples:

Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]


Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
Constraints:
1 ≤ V ≤ 106
0 ≤ E ≤ 106
0 ≤ edges[i][0], edges[i][1] < V*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000005

int *adj[MAX], *rev[MAX];
int adjSize[MAX], revSize[MAX];
int visited[MAX], stack[MAX];
int top = 0;

void addEdge(int u, int v) {
    adj[u][adjSize[u]++] = v;
    rev[v][revSize[v]++] = u;
}

void dfs1(int u) {
    visited[u] = 1;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs1(v);
    }
    stack[top++] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    for (int i = 0; i < revSize[u]; i++) {
        int v = rev[u][i];
        if (!visited[v]) dfs2(v);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(sizeof(int) * (E + 1));
        rev[i] = (int*)malloc(sizeof(int) * (E + 1));
        adjSize[i] = revSize[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < V; i++)
        if (!visited[i]) dfs1(i);

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int scc = 0;

    for (int i = V - 1; i >= 0; i--) {
        int v = stack[i];
        if (!visited[v]) {
            dfs2(v);
            scc++;
        }
    }

    printf("%d\n", scc);

    return 0;
}