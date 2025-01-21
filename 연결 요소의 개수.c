#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000

int graph[MAX_N + 1][MAX_N + 1]; // 인접 행렬
bool visited[MAX_N + 1];
int N, M;

void dfs(int node) {
    visited[node] = true;
    for (int i = 1; i <= N; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // 무방향 그래프
    }

    int components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}