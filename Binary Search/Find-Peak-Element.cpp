#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {  
                right = mid;  // 🔹 Left side-এ peak আছে
            } else {
                left = mid + 1;  // 🔹 Right side-এ peak আছে
            }
        }

        return left;  // 🔹 Peak element index
    }
};
    

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