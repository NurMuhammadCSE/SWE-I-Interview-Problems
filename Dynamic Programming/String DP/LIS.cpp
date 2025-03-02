#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLIS(vector<int>& nums, int ind, int prev, int n,
                vector<vector<int>>& dp) { 
        if (ind == n) {
            return 0;
        }

        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        int notTake = 0 + findLIS(nums, ind + 1, prev, n, dp);


        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + findLIS(nums, ind + 1, ind, n, dp);
        }

        return dp[ind][prev + 1] = max(notTake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return findLIS(nums, 0, -1, n, dp);
    }
};


int main() {
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}