#include <stdio.h>

int N, M;
int arr[50][50];

int main() {
    // �Է� �ޱ�
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &arr[i][j]);  // �� �ڸ� ���� �Է�
        }
    }

    int maxSize = 1;  // �ּ� ���簢�� ũ��

    // (i, j)�� ���簢���� �»������ Ž��
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // ������ �ִ� ũ���� ���簢�� Ž��
            for (int side = 1; side + i < N && side + j < M; side++) {
                // ������ Ȯ��
                if (arr[i][j] == arr[i][j + side] &&
                    arr[i][j] == arr[i + side][j] &&
                    arr[i][j] == arr[i + side][j + side]) {
                    int size = (side + 1) * (side + 1);  // ���簢�� ũ��
                    if (size > maxSize) {
                        maxSize = size;
                    }
                }
            }
        }
    }

    printf("%d\n", maxSize);  // ���� ū ���簢���� ũ�� ���
    return 0;
}
