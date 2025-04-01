

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
                maxCnt = max(cnt, maxCnt);
            } else {
                cnt = 0;
            }
        }
        return maxCnt;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
The above code iterates through the array once, counting the number of consecutive 1s. It has a time complexity of O(n) and a space complexity of O(1). This is efficient for large inputs.
The code uses a single loop to traverse the array, maintaining a count of consecutive 1s and updating the maximum count when a 0 is encountered. This approach is optimal for the problem and works well for large inputs. The space complexity is O(1) because it uses a constant amount of extra space for the counters.
This solution is optimal for the problem and works well for large inputs. The single loop ensures that we only traverse the array once, making it efficient in terms of time complexity. The space complexity is also minimal, as we only use a few variables to keep track of the counts.
*/