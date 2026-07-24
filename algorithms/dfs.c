#include <stdio.h>

#define MAX 10

// Goal: Explore as far as possible along one path before backtracking.

// Creating graph:
//        0
//       / \
//      1   2
//     / \
//   3   4
//       |
//       5

// Matrix:
//      0 1 2 3 4 5
//     ----------------
// 0 |  0 1 1 0 0 0
// 1 |  1 0 0 1 1 0
// 2 |  1 0 0 0 0 0
// 3 |  0 1 0 0 0 0
// 4 |  0 1 0 0 0 1
// 5 |  0 0 0 0 1 0

// Order:
// 013452

int graph[MAX][MAX];
int vertices = MAX;
int visited[MAX];

void dfs(int node) {
    visited[node] = 1;
    
    printf("%d", node);
    
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] && !visited[i]) dfs(i);
    }
}

int main()
{
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[4][5] = graph[5][4] = 1;

    printf("DFS traversal: ");
    dfs(0);

    return 0;
}
