/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

int DFS(struct Graph* graph, int vertex, int* visited, int* result, int* index) {
    visited[vertex] = 1;

    struct Node* temp = graph->adj[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (visited[adjVertex] == 1) {
            return 0;
        }

        if (visited[adjVertex] == 0) {
            if (!DFS(graph, adjVertex, visited, result, index)) {
                return 0;
            }
        }

        temp = temp->next;
    }

    visited[vertex] = 2;
    result[(*index)--] = vertex;
    return 1;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    struct Graph* graph = createGraph(numCourses);

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(graph, b, a);
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* result = (int*)malloc(numCourses * sizeof(int));
    int index = numCourses - 1;

    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (!DFS(graph, i, visited, result, &index)) {
                *returnSize = 0;
                return (int*)malloc(0);
            }
        }
    }

    *returnSize = numCourses;
    return result;
}

int main() {
    int numCourses = 4;
    int prerequisitesSize = 4;
    int prerequisitesColSize[] = {2, 2, 2, 2};

    int** prerequisites = (int**)malloc(prerequisitesSize * sizeof(int*));
    for (int i = 0; i < prerequisitesSize; i++) {
        prerequisites[i] = (int*)malloc(2 * sizeof(int));
    }

    prerequisites[0][0] = 1; prerequisites[0][1] = 0;
    prerequisites[1][0] = 2; prerequisites[1][1] = 0;
    prerequisites[2][0] = 3; prerequisites[2][1] = 1;
    prerequisites[3][0] = 3; prerequisites[3][1] = 2;

    int returnSize;
    int* order = findOrder(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize, &returnSize);

    if (returnSize == 0) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < returnSize; i++) {
            printf("%d", order[i]);
            if (i < returnSize - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }

    return 0;
}