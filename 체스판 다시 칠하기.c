#include <stdio.h>
#include <string.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int calculateRepaint(char board[50][50], int startRow, int startCol) {
    char pattern1[2] = { 'W', 'B' };
    char pattern2[2] = { 'B', 'W' };
    int repaintPattern1 = 0, repaintPattern2 = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char expected1 = pattern1[(i + j) % 2];
            char expected2 = pattern2[(i + j) % 2];

            if (board[startRow + i][startCol + j] != expected1) {
                repaintPattern1++;
            }
            if (board[startRow + i][startCol + j] != expected2) {
                repaintPattern2++;
            }
        }
    }
    return MIN(repaintPattern1, repaintPattern2);
}

int main() {
    int N, M;
    char board[50][50];
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int minRepaint = 64; // 8x8 Ä­ÀÌ ÃÖ´ë 64°³

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int repaintCount = calculateRepaint(board, i, j);
            minRepaint = MIN(minRepaint, repaintCount);
        }
    }

    printf("%d\n", minRepaint);
    return 0;
}