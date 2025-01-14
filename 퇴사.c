#include <stdio.h>

#define MAX_N 15

int T[MAX_N + 1]; // 상담 기간
int P[MAX_N + 1]; // 상담 수익
int dp[MAX_N + 2]; // dp[i]: i일에 시작할 때 얻을 수 있는 최대 수익

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    // 상담 기간과 수익 입력 받기
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    // 동적 계획법으로 최대 수익 계산
    for (int i = N; i >= 1; i--) {
        if (i + T[i] - 1 <= N) { // 상담이 N일 내에 끝나는 경우
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        }
        else { // 상담이 N일을 초과하는 경우
            dp[i] = dp[i + 1];
        }
    }

    // 최대 수익 출력
    printf("%d\n", dp[1]);

    return 0;
}
