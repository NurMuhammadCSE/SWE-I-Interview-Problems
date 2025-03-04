#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxLen = 0;
            for (int i = 0; i < s.size(); i++) {
                int hash[256] = {0};
                for (int j = i; j < s.size(); j++) {
                    if (hash[s[j]] == 1) {
                        break;
                    }
                    hash[s[j]] = 1;
                    maxLen = max(maxLen, j - i + 1);
                }
            }
            return maxLen;
        }
    };

int main() {
    Solution obj;
    string s = "abcabcbb";
    cout << obj.lengthOfLongestSubstring(s);
    return 0;
}