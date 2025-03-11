#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return {first, last};
    }
};

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

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}