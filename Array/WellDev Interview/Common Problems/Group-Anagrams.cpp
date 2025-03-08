#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        
        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end()); // Sorting to find anagram groups
            mpp[sortedStr].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto it : mpp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
