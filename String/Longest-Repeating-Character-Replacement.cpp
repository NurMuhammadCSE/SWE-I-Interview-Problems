#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0, maxLen = 0, start = 0;
        int hash[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'A']++;
            maxFreq = max(maxFreq, hash[s[i] - 'A']);

            if ((i - start + 1) - maxFreq > k) {
                hash[s[start] - 'A']--;
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution obj;
    string s = "AABABBA";
    int k = 1;
    cout << obj.characterReplacement(s, k);
    return 0;
}