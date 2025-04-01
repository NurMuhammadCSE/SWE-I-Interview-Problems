

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i = i + 1;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
The above code uses a two-pointer technique to remove duplicates from a sorted array. The first pointer (i) keeps track of the last unique element, while the second pointer (j) iterates through the array. When a new unique element is found, it is placed at the position of the first pointer, and the first pointer is incremented. This approach has a time complexity of O(n) and a space complexity of O(1), making it efficient for large inputs.
This solution is optimal for the problem and works well for large inputs. The two-pointer technique allows us to traverse the array in a single pass, which significantly reduces the time complexity compared to other methods that may require additional passes or data structures.
*/