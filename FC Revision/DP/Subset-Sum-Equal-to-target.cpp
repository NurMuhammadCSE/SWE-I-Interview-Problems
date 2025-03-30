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
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(n - 1, sum, arr);
    }
};
/*
Time Complexity: O(2n) → Exponential
Space Complexity: O(n) (Recursive Stack)
*/    

class Solution {
public:
    bool solve(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (n == 0) {
            return target == arr[n];
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }
        int notPick = solve(n - 1, target, arr, dp);
        int pick = false;
        if (arr[n] <= target) {
            pick = solve(n - 1, target - arr[n], arr, dp);
        }
        return dp[n][target] = pick || notPick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, arr, dp);
    }
};
/*
Time Complexity: O(n×sum)
Space Complexity: O(n×sum) (DP Array + Recursive Stack)
*/