/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int dist;
} Pair;

Pair heap[MAX * MAX];
int size = 0;

void swap(Pair *a, Pair *b) {
    Pair t = *a;
    *a = *b;
    *b = t;
}

void push(Pair p) {
    heap[++size] = p;
    int i = size;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

Pair pop() {
    Pair top = heap[1];
    heap[1] = heap[size--];
    int i = 1;

    while (1) {
        int l = 2 * i, r = 2 * i + 1, smallest = i;

        if (l <= size && heap[l].dist < heap[smallest].dist) smallest = l;
        if (r <= size && heap[r].dist < heap[smallest].dist) smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return top;
}

int isEmpty() {
    return size == 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;

    dist[src] = 0;
    push((Pair){src, 0});

    while (!isEmpty()) {
        Pair p = pop();
        int u = p.node;
        int d = p.dist;

        if (d > dist[u]) continue;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] > 0) {
                int newDist = dist[u] + adj[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push((Pair){v, newDist});
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}