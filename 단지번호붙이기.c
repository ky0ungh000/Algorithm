#include <stdio.h>
#include <stdlib.h>

#define MAX_N 25

int map[MAX_N][MAX_N];   // 지도
int visited[MAX_N][MAX_N]; // 방문 여부 체크
int N;                    // 지도 크기
int house_count;          // 단지 내 집의 수
int house_sizes[MAX_N * MAX_N]; // 단지 별 집의 수를 저장할 배열

// 상, 하, 좌, 우 방향
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// DFS 함수
void dfs(int x, int y) {
    // 현재 집에 방문 처리
    visited[x][y] = 1;
    house_count++;  // 단지 내 집의 수 증가

    // 4방향으로 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위 내에 있고, 집이 존재하며 아직 방문하지 않았다면
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d", &N);

    // 지도 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    // 방문 배열 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }

    int total_count = 0; // 총 단지 수
    // 각 집을 돌면서 단지를 찾는다
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                house_count = 0;  // 새로운 단지를 찾으면 집의 수 초기화
                dfs(i, j);        // DFS로 단지 탐색
                house_sizes[total_count] = house_count; // 해당 단지의 집의 수 저장
                total_count++; // 단지 수 증가
            }
        }
    }

    // 단지 수 출력
    printf("%d\n", total_count);

    // 집의 수 오름차순 정렬
    for (int i = 0; i < total_count - 1; i++) {
        for (int j = i + 1; j < total_count; j++) {
            if (house_sizes[i] > house_sizes[j]) {
                int temp = house_sizes[i];
                house_sizes[i] = house_sizes[j];
                house_sizes[j] = temp;
            }
        }
    }

    // 집의 수 출력
    for (int i = 0; i < total_count; i++) {
        printf("%d\n", house_sizes[i]);
    }

    return 0;
}