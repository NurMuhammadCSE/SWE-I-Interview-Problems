#include <vector>
#include <unordered_map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each element
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        // Step 2: Store the frequencies as pairs (frequency, element)
        vector<pair<int, int>> result;
        for (auto it : mpp) {
            result.push_back({it.second, it.first});
        }

        // Step 3: Sort the vector in descending order of frequencies
        sort(result.rbegin(), result.rend());

        // Step 4: Get the top k frequent elements
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(result[i].second);
        }

        return ans;
    }
};
