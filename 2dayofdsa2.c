#include <stdio.h>

int maxProfit(int prices[], int n) {
    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < min_price)
            min_price = prices[i];
        else if (prices[i] - min_price > max_profit)
            max_profit = prices[i] - min_price;
    }

    return max_profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    printf("Maximum Profit: %d", maxProfit(prices, n));
    return 0;
}

