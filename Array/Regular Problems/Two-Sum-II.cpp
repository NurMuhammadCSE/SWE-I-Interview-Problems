#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int total = numbers[left] + numbers[right];
            if (total == target) {
                return {left + 1, right + 1};
            } else if (total < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sol.twoSum(numbers, target);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}