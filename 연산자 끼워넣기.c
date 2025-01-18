#include <stdio.h>
#include <limits.h>

#define MAX_N 11

int N;                   // 숫자의 개수
int numbers[MAX_N];      // 수열 저장 배열
int operators[4];        // 연산자 개수 (+, -, ×, ÷)
int maxResult = INT_MIN; // 최댓값
int minResult = INT_MAX; // 최솟값

// 백트래킹 함수
void backtrack(int index, int current_result) {
    // 모든 숫자를 다 사용한 경우
    if (index == N) {
        if (current_result > maxResult) maxResult = current_result;
        if (current_result < minResult) minResult = current_result;
        return;
    }

    // 덧셈 (+)
    if (operators[0] > 0) {
        operators[0]--;
        backtrack(index + 1, current_result + numbers[index]);
        operators[0]++;
    }

    // 뺄셈 (-)
    if (operators[1] > 0) {
        operators[1]--;
        backtrack(index + 1, current_result - numbers[index]);
        operators[1]++;
    }

    // 곱셈 (×)
    if (operators[2] > 0) {
        operators[2]--;
        backtrack(index + 1, current_result * numbers[index]);
        operators[2]++;
    }

    // 나눗셈 (÷) (C++14 스타일 적용)
    if (operators[3] > 0) {
        operators[3]--;
        int next_result = current_result / numbers[index];
        // 음수 나눗셈 처리
        if (current_result < 0 && numbers[index] > 0) {
            next_result = -((-current_result) / numbers[index]);
        }
        backtrack(index + 1, next_result);
        operators[3]++;
    }
}

int main() {
    // 입력 받기
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &operators[i]);
    }

    // 백트래킹 시작 (첫 번째 숫자를 초기값으로 설정)
    backtrack(1, numbers[0]);

    // 결과 출력
    printf("%d\n%d\n", maxResult, minResult);
    return 0;
}
