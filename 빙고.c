#include <stdio.h>

#define SIZE 5

// 빙고판 상태를 업데이트하는 함수
void mark_number(int board[SIZE][SIZE], int number) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == number) {
                board[i][j] = 0; // 숫자를 0으로 변경해 지워진 상태로 표시
                return;
            }
        }
    }
}

// 빙고 줄 수를 계산하는 함수
int count_bingo_lines(int board[SIZE][SIZE]) {
    int line_count = 0;

    // 가로줄 확인
    for (int i = 0; i < SIZE; i++) {
        int row_complete = 1;
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 0) {
                row_complete = 0;
                break;
            }
        }
        if (row_complete) line_count++;
    }

    // 세로줄 확인
    for (int j = 0; j < SIZE; j++) {
        int col_complete = 1;
        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] != 0) {
                col_complete = 0;
                break;
            }
        }
        if (col_complete) line_count++;
    }

    // 대각선 확인 (왼쪽 위 -> 오른쪽 아래)
    int diag1_complete = 1;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] != 0) {
            diag1_complete = 0;
            break;
        }
    }
    if (diag1_complete) line_count++;

    // 대각선 확인 (오른쪽 위 -> 왼쪽 아래)
    int diag2_complete = 1;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][SIZE - i - 1] != 0) {
            diag2_complete = 0;
            break;
        }
    }
    if (diag2_complete) line_count++;

    return line_count;
}

int main() {
    int board[SIZE][SIZE];
    int numbers[SIZE * SIZE];

    // 빙고판 입력 받기
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // 사회자가 부르는 숫자 입력 받기
    for (int i = 0; i < SIZE * SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    // 사회자가 부르는 숫자를 하나씩 처리하며 빙고를 체크
    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        mark_number(board, numbers[turn]);

        // 현재 빙고 줄 수 계산
        int bingo_count = count_bingo_lines(board);

        // 빙고 줄이 3개 이상이면 종료
        if (bingo_count >= 3) {
            printf("%d\n", turn + 1);
            return 0;
        }
    }

    return 0;
}