#include <queue.h>

#define LEN 100

// Goal: Explore vertices level by level.

// Creating graph:
//        0
//       / \
//      1   2
//     /     \
//    3       4
//

// Matrix:
//      0 1 2 3 4
//     ------------
// 0 |  0 1 1 0 0
// 1 |  1 0 0 1 0
// 2 |  1 0 0 0 1
// 3 |  0 1 0 0 0
// 4 |  0 0 1 0 0

// Order:
// 01234

int graph[LEN][LEN];
int visited[LEN];
int vertices = 5;

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!is_empty()) {
        int curr = dequeue();

        printf("%d", curr);

        for (int i = 0; i < vertices; i++) {
            if (graph[curr][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;

    printf("BFS traversal: ");
    bfs(0);
    
    return 0;
}
