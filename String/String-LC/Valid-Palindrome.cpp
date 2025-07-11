#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(auto c : s){
            if(isalnum(c)){
                result += tolower(c);
            }
        }

        int start = 0, end = result.size() - 1;
        while(start < end){
            if(result[start] != result[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

