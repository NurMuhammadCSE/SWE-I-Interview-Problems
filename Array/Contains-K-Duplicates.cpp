#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] and abs(i - j) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] and (j - i) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};

//? Optimized Approach
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            if (mpp.find(nums[i]) != mpp.end() and abs(mpp[nums[i]] - i) <= k) {
                return true;
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};


//? Using unordered_set

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end())
                return true;

            seen.insert(nums[i]);
            if (seen.size() > k)
                seen.erase(nums[i - k]);
        }
        return false;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] == nums[j]) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        unordered_map<int, int> numMap; 

        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(nums[i]) != numMap.end()) {
                if (i - numMap[nums[i]] <= k) {
                    return true;
                }
            }
            numMap[nums[i]] = i;
        }
        return false;
    }
};
    

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << sol.containsNearbyDuplicate(nums, k);
    return 0;
}