#include <bits/stdc++.h>
using namespace std;

// 🟢 1️⃣ Recursive Approach (Naive – Exponential Time Complexity)
class Solution {
public:
    int solve(int n, vector<int> &coins, int amount) {
        if (n == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }

        int notTake = 0 + solve(n - 1, coins, amount);
        int take = INT_MAX;
        if (coins[n] <= amount) {
            take = 1 + solve(n, coins, amount - coins[n]);
        }
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int result = solve(n - 1, coins, amount);
        if (result >= 1e9) {
            return -1;
        }
        return result;
    }
};
/*
📌 Time Complexity: O(2^N) → কারণ এটি এক্সপোনেনশিয়াল গ্রোথে চলে (Recursive Tree)।
📌 Space Complexity: O(N) → রিকারশন কল স্ট্যাকের জন্য।
*/


// 🟢 2️⃣ Memoization Approach (Top-Down DP)
class Solution {
public:
    int solve(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (n == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }

        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }

        int notTake = 0 + solve(n - 1, coins, amount, dp);
        int take = INT_MAX;
        if (coins[n] <= amount) {
            take = 1 + solve(n, coins, amount - coins[n], dp);
        }
        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(n - 1, coins, amount, dp);
        if (result >= 1e9) {
            return -1;
        }
        return result;
    }
};
/*
🔥 Time & Space Complexity (Optimized)
✅ Time Complexity: O(n * amount) (Memoization Repeats Work Only Once)
✅ Space Complexity: O(n * amount) (DP Array Storage) + O(amount) (Recursion Stack)

🚀 Faster than brute-force O(2^N), but can be further optimized using Tabulation!
*/


int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << sol.coinChange(coins, amount) << endl;
    return 0;
}