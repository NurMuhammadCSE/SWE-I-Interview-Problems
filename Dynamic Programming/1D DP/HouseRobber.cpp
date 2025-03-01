#include<bits/stdc++.h>
using namespace std;

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

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<houseRobber(nums)<<endl;
    return 0;
}