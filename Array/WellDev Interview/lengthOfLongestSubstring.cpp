#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int hash[256] = {0};
            for (int j = i; j < s.size(); j++) {
                if (hash[s[j]] == 1) {
                    break;
                }
                hash[s[j]] = 1;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;  // Step 1: Initialize the max length variable
        
        for (int i = 0; i < s.size(); i++) {  // Step 2: Start from each index of the string
            int hash[256] = {0};  // Step 3: Create a hash array to track characters
            for (int j = i; j < s.size(); j++) {  // Step 4: Extend the substring with pointer 'j'
                if (hash[s[j]] == 1) {  // Step 5: If the character is already in the substring
                    break;  // Step 6: Break out of the inner loop if a duplicate is found
                }
                hash[s[j]] = 1;  // Step 7: Mark the character as visited
                maxLen = max(maxLen, j - i + 1);  // Step 8: Update the maximum length of the substring
            }
        }
        
        return maxLen;  // Step 9: Return the longest substring length
    }
};
    