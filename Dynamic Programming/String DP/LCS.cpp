#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution {
public:
    int solve(int n1, int n2, string s, string t) {
        if (n1 < 0 || n2 < 0) {
            return 0;
        }
        if (s[n1] == t[n2]) {
            return 1 + solve(n1 - 1, n2 - 1, s, t);
        } else {
            return max(solve(n1 - 1, n2, s, t), solve(n1, n2 - 1, s, t));
        }
    }
    int longestCommonSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        return solve(n1 - 1, n2 - 1, s, t);
    }
};

class Solution {
public:
    int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }

        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        if (s1[ind1] == s2[ind2]) {
            dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s1, s2, dp);
        } else {
            dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s1, s2, dp), solve(ind1, ind2 - 1, s1, s2, dp));
        }

        return dp[ind1][ind2];
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, s1, s2, dp);
    }
};


int main() {
    Solution s;
    string s1 = "abcde";
    string s2 = "ace";
    cout << s.longestCommonSubsequence(s1, s2) << endl;
    return 0;
}