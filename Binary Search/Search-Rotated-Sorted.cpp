#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        // 🔹 Step 1: Find the pivot (index of the smallest element)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int pivot = left;  // 🔹 The smallest element index (rotation point)
        left = 0, right = nums.size() - 1;

        // 🔹 Step 2: Modified Binary Search using Pivot
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int rotatedMid = (mid + pivot) % nums.size();  // 🔹 Adjusted mid considering rotation

            if (nums[rotatedMid] == target) {
                return rotatedMid;
            } else if (nums[rotatedMid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;  // 🔹 Target not found
    }
};
    


int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << solution.search(nums, target) << endl;
    return 0;
}