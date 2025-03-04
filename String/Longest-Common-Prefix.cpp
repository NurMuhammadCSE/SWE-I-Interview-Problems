#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix)) {
                prefix = prefix.substr(0, prefix.size() - 1);
            }
            if (prefix.empty()) {
                return "";
            }
        }
        return prefix;
    }
};


int main() {
    Solution obj;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << obj.longestCommonPrefix(strs);
    return 0;
}