#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xr = xr xor nums[i];
        }
        return xr;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(1)
The time complexity is O(n) because we are iterating through the array once, and the space complexity is O(1) because we are using a constant amount of extra space (the variable xr).
*/