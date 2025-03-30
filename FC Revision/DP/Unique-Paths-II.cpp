#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || grid[i][j] == 1) {
            return 0;
        }
        if (i == 0 and j == 0) {
            return 1;
        }

        int up = solve(i - 1, j, grid);
        int left = solve(i, j - 1, grid);

        return up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m - 1, n - 1, grid);
    }
};
/*
Time Complexity: Exponential
Space Complexity: O(m+n) (Recursive Stack)
*/    

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || grid[i][j] == 1) {
            return 0;
        }
        if (i == 0 and j == 0) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = solve(i - 1, j, dp, grid);
        int left = solve(i, j - 1, dp, grid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp, grid);
    }
};
/*
Time Complexity: O(m×n)
Space Complexity: O(m×n) (DP Array + Recursive Stack)
*/    

