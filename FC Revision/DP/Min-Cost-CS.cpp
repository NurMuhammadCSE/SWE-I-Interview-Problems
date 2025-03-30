#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& cost) {
        if (n < 0)
            return 0;

        return cost[n] + min(solve(n - 1, cost), solve(n - 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(solve(n - 1, cost), solve(n - 2, cost));
    }
};
/*
Time Complexity: Exponential (Very Slow)
Space Complexity: O(n) (Recursive Stack)
*/

class Solution {
public:
    int solve(int n, vector<int> &cost, vector<int> &dp) {
        if (n < 0) return 0;
        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = cost[n] + min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n) (Recursive Stack + DP Array)
*/    