#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];

                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSum = max(nums[i], nums[i] + maxSum);
            result = max(result, maxSum);
        }
        return result;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums);
    return 0;
}