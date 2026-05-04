/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** graph, int* colSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < colSize[node]; i++) {
        int next = graph[node][i];

        if (!visited[next]) {
            if (dfs(next, graph, colSize, visited, recStack))
                return true;
        } else if (recStack[next]) {
            return true;
        }
    }

    recStack[node] = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* colSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(prerequisitesSize * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][colSize[prereq]++] = course;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, colSize, visited, recStack)) {
                for (int j = 0; j < numCourses; j++) free(graph[j]);
                free(graph);
                free(colSize);
                free(visited);
                free(recStack);
                return false;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) free(graph[i]);
    free(graph);
    free(colSize);
    free(visited);
    free(recStack);

    return true;
}

int main() {
    int numCourses, prerequisitesSize;

    scanf("%d", &numCourses);
    scanf("%d", &prerequisitesSize);

    int** prerequisites = (int**)malloc(prerequisitesSize * sizeof(int*));
    int* prerequisitesColSize = (int*)malloc(prerequisitesSize * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        prerequisites[i] = (int*)malloc(2 * sizeof(int));
        prerequisitesColSize[i] = 2;
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    if (canFinish(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize))
        printf("true\n");
    else
        printf("false\n");

    for (int i = 0; i < prerequisitesSize; i++) {
        free(prerequisites[i]);
    }
    free(prerequisites);
    free(prerequisitesColSize);

    return 0;
}