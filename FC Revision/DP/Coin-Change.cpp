#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<vector<int>>& dp, vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;  // No coins needed for amount 0
        }
        if (n == 0) {
            return (amount % coins[0] == 0) ? amount / coins[0] : 1e9;  
        }
        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }

        int notPick = solve(n - 1, dp, coins, amount);  // Do not take current coin
        int pick = 1e9;
        if (coins[n] <= amount) {
            pick = 1 + solve(n, dp, coins, amount - coins[n]);  // Take current coin
        }
        return dp[n][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, dp, coins, amount);
        return (ans >= 1e9) ? -1 : ans;
    }
};
    