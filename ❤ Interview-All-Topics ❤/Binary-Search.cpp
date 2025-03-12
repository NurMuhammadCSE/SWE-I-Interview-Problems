#include<bits/stdc++.h>
using namespace std;

//? Binary Search
// Brute Force Solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans = i;
            }
        }
        return ans;
    }
};

// Optimized Solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};


//? Find Peak Element
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
    
//? Find Minimum Rotated Sorted Array
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
    
//? Search Insert Position
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

//? Single Element in Sorted Array


//? Search in a Rotated Sorted Array
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

//? Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = cols - 1;

        while (row < rows and col > -1) {
            int curr = matrix[row][col];
            if (curr == target) {
                return true;
            }
            if (target > curr) {
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
};


//? First and Last Position in Sorted Array
class Solution {
public:
    int findFirstPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;    // সম্ভাব্য প্রথম অবস্থান
                high = mid - 1; // বাঁদিকে আরো খুঁজবো
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return first;
    }

    // শেষ অবস্থান খুঁজতে Binary Search
    int findLastPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;    // সম্ভাব্য শেষ অবস্থান
                low = mid + 1; // ডানদিকে আরো খুঁজবো
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return last;
    }

    // প্রধান ফাংশন যা প্রথম ও শেষ অবস্থান খুঁজে বের করবে
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstPosition(nums, target);
        int last = findLastPosition(nums, target);
        return {first, last};
    }
};
