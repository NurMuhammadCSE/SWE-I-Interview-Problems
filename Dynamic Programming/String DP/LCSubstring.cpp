#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
  int f(int i, int j, string& s, string& t) {
          // বেস কেস: যদি একটি স্ট্রিংয়ের শেষ পৌঁছে যায়
          if (i == 0 || j == 0) {
              return 0;
          }
  
          // যদি চরিত্র দুটি মিলে যায়
          if (s[i - 1] == t[j - 1]) {
              return 1 + f(i - 1, j - 1, s, t); // একসাথে একটি চরিত্র মিলে গেছে, সাবস্ট্রিংয়ের দৈর্ঘ্য ১ বৃদ্ধি
          }
  
          // যদি মিল না থাকে, তবে কোন সাবস্ট্রিং থাকতে পারে না
          return 0;
      }
  
      int longestCommonSubstr(string s, string t) {
          int n = s.size();
          int m = t.size();
          int maxLength = 0;
  
          // সব সাবস্ট্রিংয়ের জন্য রিকার্সন কল করা
          for (int i = 1; i <= n; ++i) {
              for (int j = 1; j <= m; ++j) {
                  maxLength = max(maxLength, f(i, j, s, t)); // সর্বোচ্চ দৈর্ঘ্য বের করা
              }
          }
  
          return maxLength;
      }
  };

  
int main() {
    Solution s;
    string s1 = "abcde";
    string s2 = "ace";
    cout << s.longestCommonSubstr(s1, s2) << endl;
    return 0;
}