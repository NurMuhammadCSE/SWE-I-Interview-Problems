#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0; // Step 1: Initialize minimum price and max profit

        for (int i = 0; i < prices.size(); i++) { // Step 2: Traverse the array
            int cost = prices[i] - mini; // Step 3: Calculate potential profit
            profit = max(profit, cost);  // Step 4: Update max profit if this is the highest so far
            mini = min(mini, prices[i]); // Step 5: Update the minimum price encountered so far
        }

        return profit; // Step 6: Return the maximum profit
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; // Step 1: Track the minimum price
        int max_profit = 0;      // Step 2: Track the maximum profit

        for (int price : prices) { // Step 3: Iterate through prices
            if (price < min_price) {
                min_price = price; // Update minimum price
            } else {
                max_profit = max(max_profit, price - min_price); // Update max profit if possible
            }
        }

        return max_profit; // Return the best profit found
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                profit = max(profit, prices[j] - prices[i]);
            }
        }

        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
    