#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int N;
int S[MAX][MAX];
int visited[MAX];
int min_diff = 1e9;

void calculate_difference() {
    int start_team = 0, link_team = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i] && visited[j]) {
                start_team += S[i][j];
            }
            else if (!visited[i] && !visited[j]) {
                link_team += S[i][j];
            }
        }
    }

    int diff = abs(start_team - link_team);
    if (diff < min_diff) {
        min_diff = diff;
    }
}

void divide_teams(int idx, int count) {
    if (count == N / 2) {
        calculate_difference();
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            divide_teams(i + 1, count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    divide_teams(0, 0);

    printf("%d\n", min_diff);

    return 0;
}
