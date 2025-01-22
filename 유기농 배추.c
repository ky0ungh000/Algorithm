#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int field[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int M, N, K;

void dfs(int x, int y) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && field[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &M, &N, &K);

        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            field[y][x] = 1;
        }

        int worm_count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    dfs(j, i);
                    worm_count++;
                }
            }
        }

        printf("%d\n", worm_count);
    }

    return 0;
}
