/*There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
 

Constraints:

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int room, int** rooms, int* roomsColSize, bool* visited) {
    visited[room] = true;
    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, rooms, roomsColSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    dfs(0, rooms, roomsColSize, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

int main() {
    int roomsSize;
    scanf("%d", &roomsSize);

    int** rooms = (int**)malloc(roomsSize * sizeof(int*));
    int* roomsColSize = (int*)malloc(roomsSize * sizeof(int));

    for (int i = 0; i < roomsSize; i++) {
        scanf("%d", &roomsColSize[i]);
        rooms[i] = (int*)malloc(roomsColSize[i] * sizeof(int));
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    if (canVisitAllRooms(rooms, roomsSize, roomsColSize)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    for (int i = 0; i < roomsSize; i++) {
        free(rooms[i]);
    }
    free(rooms);
    free(roomsColSize);

    return 0;
}