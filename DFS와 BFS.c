#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1001

int graph[MAX_NODES][MAX_NODES]; // ���� ���
bool visited[MAX_NODES]; // �湮 ����
int queue[MAX_NODES]; // BFS ť

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
        graph[b][a] = 1; // ����� �׷���
    }

    // DFS ����
    dfs(v);
    printf("\n");

    // �湮 �迭 �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    // BFS ����
    bfs(v);
    printf("\n");

    return 0;
}