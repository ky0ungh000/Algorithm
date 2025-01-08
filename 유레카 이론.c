#include <stdio.h>
 
#define MAX 1000

// �ﰢ���� �����ϴ� �迭
int triangular[50]; // 50���� �ﰢ���� 1000�� ���� ����
int triangularCount = 0;

// K ������ �ﰢ���� �̸� ����Ͽ� �迭�� ����
void generateTriangularNumbers() {
    for (int i = 1; i * (i + 1) / 2 <= MAX; i++) {
        triangular[triangularCount++] = i * (i + 1) / 2;
    }
}

int isSumOfThreeTriangulars(int K) {
    for (int i = 0; i < triangularCount; i++) {
        for (int j = 0; j < triangularCount; j++) {
            for (int k = 0; k < triangularCount; k++) {
                if (triangular[i] + triangular[j] + triangular[k] == K) {
                    return 1; // ������ ���
                }
            }
        }
    }
    return 0; // �Ұ����� ���
}

int main() {
    int T, K;

    generateTriangularNumbers();

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &K);
        printf("%d\n", isSumOfThreeTriangulars(K));
    }
}
