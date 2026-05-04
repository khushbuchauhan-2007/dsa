/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) enqueue(i);
    }

    int count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) enqueue(i);
            }
        }
    }

    if (count != V) {
        printf("Cycle detected");
    }

    return 0;
}