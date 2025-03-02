#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // Base Case: যদি `s1` খালি হয়ে যায়
        if (i == 0)
            return j; // বাকি j অক্ষর ইন্সার্ট করতে হবে
        if (j == 0)
            return i; // বাকি i অক্ষর ডিলিট করতে হবে

        // যদি ফলাফল আগে থেকেই কম্পিউট করা থাকে
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // যদি দুই অক্ষর মিলে যায়
        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
        }

        // তিনটি অপশন: Insert, Delete, Replace
        dp[i][j] = 1 + min({
                            f(i, j - 1, s1, s2, dp),    // Insert
                            f(i - 1, j, s1, s2, dp),    // Delete
                            f(i - 1, j - 1, s1, s2, dp) // Replace
                        });

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, word1, word2, dp);
    }
};

    
int main() {
    Solution s;
    string s1 = "horse";
    string s2 = "ros";
    cout << s.minDistance(s1, s2) << endl;
    return 0;
}