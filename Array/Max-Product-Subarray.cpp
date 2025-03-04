#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int prod = 1;
            for (int j = i; j < nums.size(); j++) {
                prod *= nums[j];

                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxProd = max(maxProd * nums[i], nums[i]);
            result = max(result, maxProd);
        }

        return result;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxProd, minProd); // Negative হলে swap

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            result = max(result, maxProd);
        }
        return result;
    }
};
         

int main() {
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    cout << sol.maxProduct(nums);
    return 0;
}