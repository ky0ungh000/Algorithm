#include <stdio.h>

int digit_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int find_smallest_constructor(int N) {
    for (int i = 1; i < N; i++) {
        if (i + digit_sum(i) == N) return i;
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d", find_smallest_constructor(N));
    return 0;
}