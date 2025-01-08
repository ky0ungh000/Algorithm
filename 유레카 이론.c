#include <stdio.h>
 
#define MAX 1000

// 삼각수를 저장하는 배열
int triangular[50]; // 50개의 삼각수는 1000을 넘지 않음
int triangularCount = 0;

// K 이하의 삼각수를 미리 계산하여 배열에 저장
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
                    return 1; // 가능한 경우
                }
            }
        }
    }
    return 0; // 불가능한 경우
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
