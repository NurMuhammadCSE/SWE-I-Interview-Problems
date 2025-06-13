#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         return nums[k - 1];
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    cout << s.findKthLargest(nums, 2) << endl;
    return 0;
}