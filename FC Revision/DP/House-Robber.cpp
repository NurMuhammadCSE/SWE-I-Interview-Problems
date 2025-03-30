#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& nums) {
        if (n < 0) {
            return 0;
        }

        int pick = nums[n] + solve(n - 2, nums);
        int notPick = solve(n - 1, nums);
        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n - 1, nums);
    }
};
/*
Time Complexity: Exponential (Very Slow)
Space Complexity: O(n) (Recursive Stack)
*/

class Solution {
public:
    int solve(int n, vector<int> &nums, vector<int> &dp) {
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int pick = nums[n] + solve(n - 2, nums, dp);
        int notPick = solve(n - 1, nums, dp);
        return dp[n] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n) (Recursive Stack + DP Array)
*/

