#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_rank(int card1, int card2) {
    if (card1 == card2) {
        return 100 + card1; // �� ����
    }
    return (card1 + card2) % 10; // �� ����
}

double calculate_win_probability(int A, int B) {
    int all_cards[20];
    int total_cases = 0, win_cases = 0;

    // ī�� �ʱ�ȭ
    for (int i = 0; i < 10; i++) {
        all_cards[i] = i + 1;
        all_cards[i + 10] = i + 1;
    }

    // ������ ī�� ����
    int removed = 0;
    for (int i = 0; i < 20; i++) {
        if (all_cards[i] == A && removed == 0) {
            all_cards[i] = 0;
            removed++;
        }
        else if (all_cards[i] == B && removed == 1) {
            all_cards[i] = 0;
            break;
        }
    }

    // ī�� �迭 ����
    int compressed_cards[18], index = 0;
    for (int i = 0; i < 20; i++) {
        if (all_cards[i] != 0) {
            compressed_cards[index++] = all_cards[i];
        }
    }

    // ������ ���� ���
    int my_rank = calculate_rank(A, B);

    // ���� ���� ���
    for (int i = 0; i < 17; i++) {
        for (int j = i + 1; j < 18; j++) {
            total_cases++;
            int opponent_rank = calculate_rank(compressed_cards[i], compressed_cards[j]);
            if (my_rank > opponent_rank) {
                win_cases++;
            }
        }
    }

    // �̱� Ȯ�� ���
    return (double)win_cases / total_cases;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    double probability = calculate_win_probability(A, B);
    printf("%.3f\n", round(probability * 1000) / 1000);

    return 0;
}