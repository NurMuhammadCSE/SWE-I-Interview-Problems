#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string str) {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }

        int maxLen = 1;
        string maxStr = s.substr(0, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i + maxLen; j <= n; j++) {
                if (j - i > maxLen and isPalindrome(s.substr(i, j - i))) {
                    maxLen = j - i;
                    maxStr = s.substr(i, j - i);
                }
            }
        }
        return maxStr;
    }
};