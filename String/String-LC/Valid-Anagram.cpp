#include<bits/stdc++.h>
using namespace std;

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
    Solution obj;
    string s = "anagram";
    string t = "nagaram";
    cout << obj.isAnagram(s, t);
    return 0;
}