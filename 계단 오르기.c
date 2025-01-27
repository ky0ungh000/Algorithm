#include <stdio.h>

#define MAX 301  // ��� �ִ� ���� 300�� + 1(�迭 �ε��� ���ǻ�)

int main() {
    int n;  // ��� ����
    int stair[MAX] = { 0 };  // ��� ���� ���� �迭
    int dp[MAX] = { 0 };  // DP ���̺�

    // �Է� �ޱ�
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &stair[i]);
    }

    // �ʱⰪ ����
    dp[1] = stair[1];  // ù ��° ��� ����
    if (n >= 2) {
        dp[2] = stair[1] + stair[2];  // ù ��° + �� ��° ��� ����
    }
    if (n >= 3) {
        dp[3] = (stair[1] + stair[3] > stair[2] + stair[3]) ? stair[1] + stair[3] : stair[2] + stair[3];
    }

    // ��ȭ���� �̿��� DP ���
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 2] + stair[i] > dp[i - 3] + stair[i - 1] + stair[i])
            ? dp[i - 2] + stair[i]
            : dp[i - 3] + stair[i - 1] + stair[i];
    }

    // �ִ� ���
    printf("%d\n", dp[n]);

    return 0;
}