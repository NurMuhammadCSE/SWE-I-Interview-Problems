


class Solution {
public:
    bool ls(vector<int> nums, int x) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int maxCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int cnt = 1;

            while (ls(nums, x + 1) == true) {
                x++;
                cnt++;
            }
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
The above code is a brute force solution that checks all elements in the array to find the longest consecutive sequence. It has a time complexity of O(n^2) and a space complexity of O(1). This is not efficient for large inputs.
The brute force approach is not optimal for large inputs, as it checks all elements in the array, leading to a quadratic time complexity. This can be improved using a hash set or sorting, which reduces the time complexity to O(n) while maintaining a space complexity of O(n).
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int maxCnt = 0;

        for (int num : numsSet) {
            if (numsSet.count(num - 1) == 0) {
                int x = num;
                int cnt = 1;

                while (numsSet.count(x + 1)) {
                    x++;
                    cnt++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
The above code uses a hash set to store the elements of the array. It iterates through the set and checks if the current number is the start of a sequence (i.e., if the previous number is not in the set). If it is, it counts the length of the sequence by checking for consecutive numbers. This approach has a time complexity of O(n) and a space complexity of O(n), making it much more efficient than the brute force solution.
*/