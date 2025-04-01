

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i + 1, j + 1};
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
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int more = target - nums[i];
            if (mpp.find(more) != mpp.end()) {
                return {mpp[more] + 1, i + 1};
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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
The above code uses a two-pointer approach to find the two numbers that add up to the target. It assumes that the input array is sorted. The left pointer starts at the beginning of the array, and the right pointer starts at the end. We calculate the sum of the two numbers at these pointers and adjust the pointers based on whether the sum is less than or greater than the target. This approach has a time complexity of O(n) and a space complexity of O(1), making it efficient for large inputs.
*/