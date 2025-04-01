

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
The above code is a brute force solution that checks all pairs of indices to find the two numbers that add up to the target. It has a time complexity of O(n^2) and a space complexity of O(1). This is not efficient for large inputs.
The brute force approach is not optimal for large inputs, as it checks all pairs of indices, leading to a quadratic time complexity. This can be improved using a hash map or a two-pointer technique, which reduces the time complexity to O(n) while maintaining a space complexity of O(n).
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int more = target - nums[i];
            if (mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
The above code uses a hash map to store the indices of the numbers as we iterate through the array. For each number, we check if its complement (target - number) exists in the hash map. If it does, we return the indices of the two numbers. This approach has a time complexity of O(n) and a space complexity of O(n), making it much more efficient than the brute force solution.
This solution is optimal for the problem and works well for large inputs. The hash map allows for constant time lookups, which significantly reduces the overall time complexity compared to the brute force approach.
*/