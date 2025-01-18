#include <stdio.h>
#include <limits.h>

#define MAX_N 11

int N;                   // ������ ����
int numbers[MAX_N];      // ���� ���� �迭
int operators[4];        // ������ ���� (+, -, ��, ��)
int maxResult = INT_MIN; // �ִ�
int minResult = INT_MAX; // �ּڰ�

// ��Ʈ��ŷ �Լ�
void backtrack(int index, int current_result) {
    // ��� ���ڸ� �� ����� ���
    if (index == N) {
        if (current_result > maxResult) maxResult = current_result;
        if (current_result < minResult) minResult = current_result;
        return;
    }

    // ���� (+)
    if (operators[0] > 0) {
        operators[0]--;
        backtrack(index + 1, current_result + numbers[index]);
        operators[0]++;
    }

    // ���� (-)
    if (operators[1] > 0) {
        operators[1]--;
        backtrack(index + 1, current_result - numbers[index]);
        operators[1]++;
    }

    // ���� (��)
    if (operators[2] > 0) {
        operators[2]--;
        backtrack(index + 1, current_result * numbers[index]);
        operators[2]++;
    }

    // ������ (��) (C++14 ��Ÿ�� ����)
    if (operators[3] > 0) {
        operators[3]--;
        int next_result = current_result / numbers[index];
        // ���� ������ ó��
        if (current_result < 0 && numbers[index] > 0) {
            next_result = -((-current_result) / numbers[index]);
        }
        backtrack(index + 1, next_result);
        operators[3]++;
    }
}

int main() {
    // �Է� �ޱ�
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &operators[i]);
    }

    // ��Ʈ��ŷ ���� (ù ��° ���ڸ� �ʱⰪ���� ����)
    backtrack(1, numbers[0]);

    // ��� ���
    printf("%d\n%d\n", maxResult, minResult);
    return 0;
}
