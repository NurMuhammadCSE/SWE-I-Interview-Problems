#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
            return;

        grid[i][j] = '0'; // Visited mark
        
        // 4-Direction DFS
        dfs(grid, i+1, j); // নিচে
        dfs(grid, i-1, j); // উপরে
        dfs(grid, i, j+1); // ডানে
        dfs(grid, i, j-1); // বামে
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++; // নতুন দ্বীপ পাওয়ায় Counter বাড়াও
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution obj;
    cout << obj.numIslands(grid); // Output: 3
    return 0;
}
