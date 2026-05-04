/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void addEdge(struct Node* adj[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

void BFS(struct Node* adj[], int n, int start) {
    int visited[MAX] = {0};
    struct Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS Traversal: ");

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        struct Node* temp = adj[current];
        while (temp != NULL) {
            int adjVertex = temp->data;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int n, e, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[MAX];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(adj, src, dest);
        addEdge(adj, dest, src);
    }

    printf("Enter source vertex for BFS: ");
    scanf("%d", &start);

    BFS(adj, n, start);

    return 0;
}