#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (i == 0 and j == 0) {
            return 1;
        }
        int right = solve(i - 1, j);
        int down = solve(i, j - 1);
        return right + down;
    }
    int uniquePaths(int m, int n) { 
        return solve(m - 1, n - 1); 
    }
};
/*
Time Complexity: Exponential
Space Complexity: O(m+n) (Recursive Stack)
*/    

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (i == 0 and j == 0)
            return 1;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = solve(i - 1, j, dp);
        int left = solve(i, j - 1, dp);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};
/*
Time Complexity: O(m×n)
Space Complexity: O(m×n) (DP Array + Recursive Stack)
*/    

