#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_rank(int card1, int card2) {
    if (card1 == card2) {
        return 100 + card1; // 땡 족보
    }
    return (card1 + card2) % 10; // 끗 족보
}

double calculate_win_probability(int A, int B) {
    int all_cards[20];
    int total_cases = 0, win_cases = 0;

    // 카드 초기화
    for (int i = 0; i < 10; i++) {
        all_cards[i] = i + 1;
        all_cards[i + 10] = i + 1;
    }

    // 영학이 카드 제거
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

    // 카드 배열 압축
    int compressed_cards[18], index = 0;
    for (int i = 0; i < 20; i++) {
        if (all_cards[i] != 0) {
            compressed_cards[index++] = all_cards[i];
        }
    }

    // 영학이 족보 계산
    int my_rank = calculate_rank(A, B);

    // 상대방 족보 계산
    for (int i = 0; i < 17; i++) {
        for (int j = i + 1; j < 18; j++) {
            total_cases++;
            int opponent_rank = calculate_rank(compressed_cards[i], compressed_cards[j]);
            if (my_rank > opponent_rank) {
                win_cases++;
            }
        }
    }

    // 이길 확률 계산
    return (double)win_cases / total_cases;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    double probability = calculate_win_probability(A, B);
    printf("%.3f\n", round(probability * 1000) / 1000);

    return 0;
}