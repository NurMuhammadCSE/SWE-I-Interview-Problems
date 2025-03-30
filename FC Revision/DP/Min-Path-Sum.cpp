#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& grid) {
        if (m < 0 || n < 0) {
            return INT_MAX;
        }
        if (m == 0 and n == 0) {
            return grid[m][n];
        }

        int up = solve(m - 1, n, grid);
        int left = solve(m, n - 1, grid);

        return grid[m][n] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m - 1, n - 1, grid);
    }
};
/*
Time Complexity: O(2(m+n)) → Exponential
Space Complexity: O(m+n) (Recursive Stack)
*/    


class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (m < 0 || n < 0) {
            return INT_MAX;
        }
        if (m == 0 and n == 0) {
            return grid[m][n];
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int up = solve(m - 1, n, grid, dp);
        int left = solve(m, n - 1, grid, dp);

        return dp[m][n] = grid[m][n] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};
/*
Time Complexity: O(m×n)
Space Complexity: O(m×n) (DP Array + Recursive Stack)
*/