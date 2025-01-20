#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1001

int graph[MAX_NODES][MAX_NODES]; // 인접 행렬
bool visited[MAX_NODES]; // 방문 여부
int queue[MAX_NODES]; // BFS 큐

int n, m, v;

void dfs(int node) {
    printf("%d ", node);
    visited[node] = true;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 1; i <= n; i++) {
            if (graph[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1; // 양방향 그래프
    }

    // DFS 수행
    dfs(v);
    printf("\n");

    // 방문 배열 초기화
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    // BFS 수행
    bfs(v);
    printf("\n");

    return 0;
}