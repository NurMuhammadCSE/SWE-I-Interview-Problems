#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        
        // If out of bounds, return a very large number
        if (i >= m || j >= n) {
            return INT_MAX;
        }
        
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        // If the value is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Recurse for the two possible moves: down and right
        int down = solve(grid, i + 1, j, dp);
        int right = solve(grid, i, j + 1, dp);

        // Store the minimum sum in dp[i][j]
        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, 0, 0, dp);
    }
};

int main(){
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution obj;
    cout<<obj.minPathSum(grid)<<endl;
    return 0;
}