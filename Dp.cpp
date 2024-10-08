#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem using DP
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP table, dp[i][w] will store the maximum value for weight w using first i items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or zero weight
            } else if (weights[i - 1] <= w) {
                // Max value obtained by including or excluding the item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // If the item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell of the table contains the result
    return dp[n][W];
}

int main() {
    int n = 4; // Number of items
    int W = 7; // Knapsack capacity

    vector<int> values = {16, 19, 23, 28};  // Values of the items
    vector<int> weights = {2, 3, 4, 5};    // Weights of the items

    int maxProfit = knapsack(W, weights, values, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
