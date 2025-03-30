#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int n, int target, vector<int>& arr) {
        if (target == 0)
            return true;
        if (n == 0) {
            return target == arr[n];
        }
        int notPick = solve(n - 1, target, arr);
        int pick = false;
        if (arr[n] <= target) {
            pick = solve(n - 1, target - arr[n], arr);
        }
        return pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        return solve(n - 1, target, nums);
    }
};
/*
Time Complexity: O(2n) → Exponential
Space Complexity: O(n) (Recursive Stack)
*/    

class Solution {
public:
    bool solve(int n, int target, vector<vector<int>>& dp, vector<int>& arr) {
        if (target == 0)
            return true;
        if (n == 0) {
            return target == arr[n];
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }
        int notPick = solve(n - 1, target, dp, arr);
        int pick = false;
        if (arr[n] <= target) {
            pick = solve(n - 1, target - arr[n], dp, arr);
        }
        return dp[n][target] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, dp, nums);
    }
};
/*
Time Complexity: O(n×sum/2)
Space Complexity: O(n×sum/2) (DP Array + Recursive Stack)
*/    