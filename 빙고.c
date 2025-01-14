#include <stdio.h>

#define SIZE 5

// ������ ���¸� ������Ʈ�ϴ� �Լ�
void mark_number(int board[SIZE][SIZE], int number) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == number) {
                board[i][j] = 0; // ���ڸ� 0���� ������ ������ ���·� ǥ��
                return;
            }
        }
    }
}

// ���� �� ���� ����ϴ� �Լ�
int count_bingo_lines(int board[SIZE][SIZE]) {
    int line_count = 0;

    // ������ Ȯ��
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

    // ������ Ȯ��
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

    // �밢�� Ȯ�� (���� �� -> ������ �Ʒ�)
    int diag1_complete = 1;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] != 0) {
            diag1_complete = 0;
            break;
        }
    }
    if (diag1_complete) line_count++;

    // �밢�� Ȯ�� (������ �� -> ���� �Ʒ�)
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

    // ������ �Է� �ޱ�
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // ��ȸ�ڰ� �θ��� ���� �Է� �ޱ�
    for (int i = 0; i < SIZE * SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    // ��ȸ�ڰ� �θ��� ���ڸ� �ϳ��� ó���ϸ� ���� üũ
    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        mark_number(board, numbers[turn]);

        // ���� ���� �� �� ���
        int bingo_count = count_bingo_lines(board);

        // ���� ���� 3�� �̻��̸� ����
        if (bingo_count >= 3) {
            printf("%d\n", turn + 1);
            return 0;
        }
    }

    return 0;
}