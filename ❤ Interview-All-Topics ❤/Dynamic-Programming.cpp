#include<bits/stdc++.h>
using namespace std;

//? Fibonacci Number

class Solution {
public:
    int fib(int n) {
        if(n <= 2){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};

//? Climbing Stairs

// 🟢 1️⃣ Recursive Approach (Naive – Exponential Time Complexity)
int climbingStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (n <= n) {
        return n;
    }

    return climbingStairs(n - 1) + climbingStairs(n - 2);
}
/*
⏳ Time & Space Complexity:
Time Complexity: O(2^N) (Exponential ❌)
Space Complexity: O(N) (Recursive Stack)
*/

// 🟢 2️⃣ Memoization Approach (Top-Down DP)
class Solution {
public:
    int climbHelper(int n, vector<int>& dp) {
        if (n <= 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = climbHelper(n - 1, dp) + climbHelper(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climbHelper(n, dp);
    }
};


//? House Robber

int solve(int ind, vector<int> nums){
    if(ind == 0){
        return nums[ind];
    }

    if(ind < 0){
        return 0;
    }

    int pick = nums[ind] + solve(ind-2, nums);
    int notPick = 0 + solve(ind-1, nums);

    return max(pick, notPick);
}

int houseRobber(vector<int> nums){
    return solve(nums.size()-1, nums);
}

// Memoization
class Solution {
public:
    int solve(int ind, vector<int> &nums, vector<int> &dp) {
        if (ind == 0)
            return nums[ind];

        if (ind < 0)
            return 0;

        if (dp[ind] != -1) {
            return dp[ind];
        }

        int pick = nums[ind] + solve(ind - 2, nums, dp);
        int notPick = 0 + solve(ind - 1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(n - 1, nums, dp);
    }
};


//? Unique Paths - I

class Solution {
    public:
        int solve(int i, int j) {
            if (i == 0 and j == 0) {
                return 1;
            }
    
            if (i < 0 || j < 0) {
                return 0;
            }
    
            int up = solve(i - 1, j);
            int left = solve(i, j - 1);
    
            return up + left;
        }
    
        int uniquePaths(int m, int n) { return solve(m - 1, n - 1); 
    }
};


// Memoization
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> dp) {
        if (i == 0 and j == 0) {
            return 1;
        }

        if (i < 0 || j < 0) {
            return 0;
        }

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


//? Unique Paths - II

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


//? Minimum Path Sum
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


//? Coin Change

// 🟢 1️⃣ Recursive Approach (Naive – Exponential Time Complexity)
class Solution {
public:
    int solve(int n, vector<int> &coins, int amount) {
        if (n == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }

        int notTake = 0 + solve(n - 1, coins, amount);
        int take = INT_MAX;
        if (coins[n] <= amount) {
            take = 1 + solve(n, coins, amount - coins[n]);
        }
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int result = solve(n - 1, coins, amount);
        if (result >= 1e9) {
            return -1;
        }
        return result;
    }
};
/*
📌 Time Complexity: O(2^N) → কারণ এটি এক্সপোনেনশিয়াল গ্রোথে চলে (Recursive Tree)।
📌 Space Complexity: O(N) → রিকারশন কল স্ট্যাকের জন্য।
*/


// 🟢 2️⃣ Memoization Approach (Top-Down DP)
class Solution {
public:
    int solve(int n, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (n == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }

        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }

        int notTake = 0 + solve(n - 1, coins, amount, dp);
        int take = INT_MAX;
        if (coins[n] <= amount) {
            take = 1 + solve(n, coins, amount - coins[n], dp);
        }
        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(n - 1, coins, amount, dp);
        if (result >= 1e9) {
            return -1;
        }
        return result;
    }
};
/*
🔥 Time & Space Complexity (Optimized)
✅ Time Complexity: O(n * amount) (Memoization Repeats Work Only Once)
✅ Space Complexity: O(n * amount) (DP Array Storage) + O(amount) (Recursion Stack)

🚀 Faster than brute-force O(2^N), but can be further optimized using Tabulation!
*/


//? Buy and Sell - I
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0; // Step 1: Initialize minimum price and max profit

        for (int i = 0; i < prices.size(); i++) { // Step 2: Traverse the array
            int cost = prices[i] - mini; // Step 3: Calculate potential profit
            profit = max(profit, cost);  // Step 4: Update max profit if this is the highest so far
            mini = min(mini, prices[i]); // Step 5: Update the minimum price encountered so far
        }

        return profit; // Step 6: Return the maximum profit
    }
};

