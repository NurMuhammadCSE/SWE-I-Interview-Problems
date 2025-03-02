#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n1, int n2, string& s, string& t, vector<vector<int>>& dp) {
        if (n1 < 0 || n2 < 0) {
            return 0;
        }

        if (dp[n1][n2] != -1) {
            return dp[n1][n2];
        }

        if (s[n1] == t[n2]) {
            dp[n1][n2] = 1 + f(n1 - 1, n2 - 1, s, t, dp);
        } else {
            dp[n1][n2] = max(f(n1 - 1, n2, s, t, dp), f(n1, n2 - 1, s, t, dp));
        }

        return dp[n1][n2];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        return f(s.size() - 1, t.size() - 1, s, t, dp);
    }
};

    
int main() {
    Solution s;
    string str = "bbbab";
    cout << s.longestPalindromeSubseq(str) << endl;
    return 0;
}