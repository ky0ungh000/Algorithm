#include <stdio.h>

int main() {
    int M; // 컵 위치를 바꾼 횟수
    int ball_position = 1; // 공의 초기 위치는 1번 컵 아래

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int X, Y; // 위치를 바꿀 두 컵의 번호
        scanf("%d %d", &X, &Y);

        // 공의 위치가 교환하는 컵 중 하나에 있으면 위치 변경
        if (ball_position == X) {
            ball_position = Y;
        }
        else if (ball_position == Y) {
            ball_position = X;
        }
    }

    printf("%d\n", ball_position);

    return 0;
}