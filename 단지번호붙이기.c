#include <stdio.h>
#include <stdlib.h>

#define MAX_N 25

int map[MAX_N][MAX_N];   // ����
int visited[MAX_N][MAX_N]; // �湮 ���� üũ
int N;                    // ���� ũ��
int house_count;          // ���� �� ���� ��
int house_sizes[MAX_N * MAX_N]; // ���� �� ���� ���� ������ �迭

// ��, ��, ��, �� ����
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// DFS �Լ�
void dfs(int x, int y) {
    // ���� ���� �湮 ó��
    visited[x][y] = 1;
    house_count++;  // ���� �� ���� �� ����

    // 4�������� Ž��
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // ���� ���� �ְ�, ���� �����ϸ� ���� �湮���� �ʾҴٸ�
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d", &N);

    // ���� �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    // �湮 �迭 �ʱ�ȭ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }

    int total_count = 0; // �� ���� ��
    // �� ���� ���鼭 ������ ã�´�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                house_count = 0;  // ���ο� ������ ã���� ���� �� �ʱ�ȭ
                dfs(i, j);        // DFS�� ���� Ž��
                house_sizes[total_count] = house_count; // �ش� ������ ���� �� ����
                total_count++; // ���� �� ����
            }
        }
    }

    // ���� �� ���
    printf("%d\n", total_count);

    // ���� �� �������� ����
    for (int i = 0; i < total_count - 1; i++) {
        for (int j = i + 1; j < total_count; j++) {
            if (house_sizes[i] > house_sizes[j]) {
                int temp = house_sizes[i];
                house_sizes[i] = house_sizes[j];
                house_sizes[j] = temp;
            }
        }
    }

    // ���� �� ���
    for (int i = 0; i < total_count; i++) {
        printf("%d\n", house_sizes[i]);
    }

    return 0;
}