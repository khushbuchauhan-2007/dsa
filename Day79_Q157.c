/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int v, w;
} Edge;

typedef struct {
    Edge edges[MAX];
    int size;
} AdjList;

typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode heap[MAX];
    int size;
} MinHeap;

AdjList graph[MAX];
int dist[MAX];

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while (i && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap *h, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap *h, int node, int distVal) {
    h->heap[h->size].node = node;
    h->heap[h->size].dist = distVal;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode pop(MinHeap *h) {
    HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

void addEdge(int u, int v, int w) {
    graph[u].edges[graph[u].size].v = v;
    graph[u].edges[graph[u].size].w = w;
    graph[u].size++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) graph[i].size = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int source;
    scanf("%d", &source);

    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[source] = 0;
    push(&h, source, 0);

    while (h.size > 0) {
        HeapNode top = pop(&h);
        int u = top.node;

        for (int i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].v;
            int w = graph[u].edges[i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}