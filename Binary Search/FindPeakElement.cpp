#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << solution.findPeakElement(nums) << endl;
    return 0;
}