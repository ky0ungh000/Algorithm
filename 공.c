#include <stdio.h>

int main() {
    int M; // �� ��ġ�� �ٲ� Ƚ��
    int ball_position = 1; // ���� �ʱ� ��ġ�� 1�� �� �Ʒ�

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int X, Y; // ��ġ�� �ٲ� �� ���� ��ȣ
        scanf("%d %d", &X, &Y);

        // ���� ��ġ�� ��ȯ�ϴ� �� �� �ϳ��� ������ ��ġ ����
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