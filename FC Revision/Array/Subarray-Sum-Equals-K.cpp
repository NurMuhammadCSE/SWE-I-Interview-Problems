

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];

                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
The above code is a brute force solution that checks all subarrays to find the number of subarrays that sum up to k. It has a time complexity of O(n^2) and a space complexity of O(1). This is not efficient for large inputs.
The brute force approach is not optimal for large inputs, as it checks all subarrays, leading to a quadratic time complexity. This can be improved using a hash map or a prefix sum technique, which reduces the time complexity to O(n) while maintaining a space complexity of O(n).
*/