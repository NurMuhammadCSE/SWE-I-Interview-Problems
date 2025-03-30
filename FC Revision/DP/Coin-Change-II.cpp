#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }
        if (n == 0) {
            return (amount % coins[0] == 0) ? 1 : 0;
        }
        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }
        int notPick = solve(n - 1, amount, coins, dp);
        int pick = 0;
        if (coins[n] <= amount) {
            pick = solve(n, amount - coins[n], coins, dp);
        }
        return dp[n][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};