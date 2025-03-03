#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int l = 0, h = nums.size() - 1;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] <= target) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
            return l;
        }
    };

int main() {
    Solution obj;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << obj.searchInsert(nums, target) << endl;
    return 0;
}