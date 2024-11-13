// This solution follows the pseudocode outlined in the instructional video on YouTube by Algo Engine.
// Reference URL: https://www.youtube.com/watch?v=ioFPBdChabY&ab_channel=AlgoEngine

int max(int a, int b);

// Dynamic Programming
int maxProfit(int* prices, int pricesSize) {
    int buy = prices[0], sell, profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        sell = prices[i];

        if(prices[i] < buy)
            buy = prices[i];
        else
            profit = max(profit, sell - buy);
        
    }

    return profit;
}

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

// prices = [7,3,8,1,5,4]
// buy             ^
// sell                 ^
// prifit        5   4  3
