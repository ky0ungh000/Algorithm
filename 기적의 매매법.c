#include <stdio.h>

#define DAYS 14

int BNP(int cash, int prices[]) {
    int stocks = 0;

    for (int i = 0; i < DAYS; i++) {
        if (cash >= prices[i]) {
            int max_stocks = cash / prices[i];
            stocks += max_stocks;
            cash -= max_stocks * prices[i];
        }
    }

    return cash + stocks * prices[DAYS - 1];
}

int TIMING(int cash, int prices[]) {
    int stocks = 0;
    int trend[DAYS] = { 0 };

    for (int i = 1; i < DAYS; i++) {
        if (prices[i] > prices[i - 1]) {
            trend[i] = 1;
        }
        else if (prices[i] < prices[i - 1]) {
            trend[i] = -1;
        }
        else {
            trend[i] = 0;
        }
    }

    for (int i = 2; i < DAYS; i++) {
        int sum_trend = trend[i - 2] + trend[i - 1] + trend[i];
        if (sum_trend == -3) {
            if (cash >= prices[i]) {
                int max_stocks = cash / prices[i];
                stocks += max_stocks;
                cash -= max_stocks * prices[i];
            }
        }
        else if (sum_trend == 3) {
            cash += stocks * prices[i];
            stocks = 0;
        }
    }

    return cash + stocks * prices[DAYS - 1];
}

int main() {
    int cash;
    int prices[DAYS];

    scanf("%d", &cash);
    for (int i = 0; i < DAYS; i++) {
        scanf("%d", &prices[i]);
    }

    int bnp_assets = BNP(cash, prices);
    int timing_assets = TIMING(cash, prices);

    if (bnp_assets > timing_assets) {
        printf("BNP\n");
    }
    else if (bnp_assets < timing_assets) {
        printf("TIMING\n");
    }
    else {
        printf("SAMESAME\n");
    }

    return 0;
}
