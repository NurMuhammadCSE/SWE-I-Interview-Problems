#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filter = "";
        for (auto c : s) {
            if (isalnum(c)) {
                filter += tolower(c);
            }
        }

        int left = 0, right = filter.size() - 1;
        while (left < right) {
            if (filter[left] != filter[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    string s;
    cin >> s;
    Solution obj;
    cout << obj.isPalindrome(s);
    return 0;
}