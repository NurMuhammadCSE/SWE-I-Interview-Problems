#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        // If we are out of bounds or at a blocked cell, return 0
        if (i >= m || j >= n || grid[i][j] == 1) {
            return 0;
        }

        // If we have reached the destination cell, return 1
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Calculate the number of paths by moving down and right
        int right = solve(grid, i, j + 1, dp);
        int down = solve(grid, i + 1, j, dp);

        // Store the result in the dp array and return it
        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, 0, 0, dp);
    }
};
  
int main(){
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution obj;
    cout<<obj.uniquePathsWithObstacles(obstacleGrid)<<endl;
    return 0;
}