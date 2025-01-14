#include <stdio.h>

#define MAX_N 15

int T[MAX_N + 1]; // ��� �Ⱓ
int P[MAX_N + 1]; // ��� ����
int dp[MAX_N + 2]; // dp[i]: i�Ͽ� ������ �� ���� �� �ִ� �ִ� ����

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    // ��� �Ⱓ�� ���� �Է� �ޱ�
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    // ���� ��ȹ������ �ִ� ���� ���
    for (int i = N; i >= 1; i--) {
        if (i + T[i] - 1 <= N) { // ����� N�� ���� ������ ���
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
        }
        else { // ����� N���� �ʰ��ϴ� ���
            dp[i] = dp[i + 1];
        }
    }

    // �ִ� ���� ���
    printf("%d\n", dp[1]);

    return 0;
}
