#include <stdio.h>

#define MAX 301  // 계단 최대 개수 300개 + 1(배열 인덱스 편의상)

int main() {
    int n;  // 계단 개수
    int stair[MAX] = { 0 };  // 계단 점수 저장 배열
    int dp[MAX] = { 0 };  // DP 테이블

    // 입력 받기
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &stair[i]);
    }

    // 초기값 설정
    dp[1] = stair[1];  // 첫 번째 계단 점수
    if (n >= 2) {
        dp[2] = stair[1] + stair[2];  // 첫 번째 + 두 번째 계단 점수
    }
    if (n >= 3) {
        dp[3] = (stair[1] + stair[3] > stair[2] + stair[3]) ? stair[1] + stair[3] : stair[2] + stair[3];
    }

    // 점화식을 이용한 DP 계산
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 2] + stair[i] > dp[i - 3] + stair[i - 1] + stair[i])
            ? dp[i - 2] + stair[i]
            : dp[i - 3] + stair[i - 1] + stair[i];
    }

    // 최댓값 출력
    printf("%d\n", dp[n]);

    return 0;
}