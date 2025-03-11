#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
        }
        return mini;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] > nums[h]) {  
                l = mid + 1;  // 🔹 Pivot ডান দিকে আছে
            } else {
                h = mid;  // 🔹 Pivot mid বা বামে আছে
            }
        }
        
        return nums[l];  // 🔹 Minimum element
    }
};
    

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            // if (nums[start] < nums[end]) {
            //     return nums[start];
            // }
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};


// ChatGPT
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If mid element is greater than the high element, 
            // it means the smallest element is to the right of mid
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            // Otherwise, the smallest element is to the left of mid (including mid)
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};
    

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.findMin(nums) << endl;
    return 0;
}