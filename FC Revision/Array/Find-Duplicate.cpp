

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return 0;
    }
};
/*
Time Complexity: O(n log n)
Space Complexity: O(1)
The above code sorts the array and then checks for duplicates in a single pass. The sorting step takes O(n log n) time, and the subsequent pass takes O(n) time, resulting in an overall time complexity of O(n log n). The space complexity is O(1) since we are not using any additional data structures that grow with input size.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i])) {
                return nums[i];
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
The above code uses an unordered set to keep track of the numbers we have seen so far. For each number, we check if it is already in the set. If it is, we return that number as the duplicate. This approach has a time complexity of O(n) and a space complexity of O(n), making it efficient for large inputs.
*/