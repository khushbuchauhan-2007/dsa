/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int dist;
} Pair;

Pair heap[10001];
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

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    int adj[101][101];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = -1;

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u][v] = w;
    }

    int dist[101];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    size = 0;
    dist[k] = 0;
    push((Pair){k, 0});

    while (!isEmpty()) {
        Pair p = pop();
        int u = p.node;
        int d = p.dist;

        if (d > dist[u]) continue;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != -1) {
                int newDist = dist[u] + adj[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push((Pair){v, newDist});
                }
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}

int main() {
    int timesSize = 3;
    int n = 4, k = 2;

    int data[3][3] = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int* times[3];
    for (int i = 0; i < timesSize; i++) {
        times[i] = data[i];
    }

    int timesColSize[3] = {3,3,3};

    int result = networkDelayTime(times, timesSize, timesColSize, n, k);
    printf("%d\n", result);

    return 0;
}