#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& Arr, int ind, int buy, int n, vector<vector<int>>& dp) {
        if (ind == n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit;
        if (buy == 0) { // We can buy the stock
            profit = max(0 + solve(Arr, ind + 1, 0, n, dp),
                            -Arr[ind] + solve(Arr, ind + 1, 1, n, dp));
        }

        if (buy == 1) { // We can sell the stock
            profit = max(0 + solve(Arr, ind + 1, 1, n, dp),
                            Arr[ind] + solve(Arr, ind + 1, 0, n, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        if (n == 0)
            return 0; // Edge case: No stocks to trade.

        int ans = solve(prices, 0, 0, n, dp);
        return ans;
    }
    // int maxProfit(vector<int>& prices) {
    //     int maxProfit = 0;

    //     for(int i=1;i<prices.size(); i++){
    //         if(prices[i] > prices[i-1]){
    //             maxProfit += prices[i] - prices[i-1];
    //         }
    //     }
    //     return maxProfit;
    // }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}