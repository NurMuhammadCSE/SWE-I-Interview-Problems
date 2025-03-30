#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
/*
Overlapping Subproblems: একই সাব-প্রব্লেম বারবার ক্যালকুলেট করছে।
Time Complexity:(Exponential) → খুবই ধীরগতির
Space Complexity: O(n) (Recursive Stack)
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n <= 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n) (Recursive Stack + DP array)
*/    