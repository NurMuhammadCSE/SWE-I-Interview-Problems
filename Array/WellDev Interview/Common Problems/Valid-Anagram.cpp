#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        for (auto c : s) {
            if (freq.find(c) != freq.end() || freq[c] == 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> inputS(256, 0);
        int n = s.length();
        if (n != t.length())
            return false;
        for (int i = 0; i < n; i++) {
            inputS[s[i]]++;
            inputS[t[i]]--;
        }
        for (int count : inputS) {
            if (count != 0)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}