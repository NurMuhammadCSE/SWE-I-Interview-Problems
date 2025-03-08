#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Step 1: Preprocess the string
        string filteredString = "";
        for (char c : s) {
            // Step 1.1: Convert to lowercase if it's a letter or digit
            if (isalnum(c)) {
                filteredString += tolower(c);
            }
        }

        // Step 2: Check if the string is a palindrome
        int left = 0, right = filteredString.size() - 1;
        while (left < right) {
            if (filteredString[left] != filteredString[right]) {
                return false;  // If they are not the same, it's not a palindrome
            }
            left++;
            right--;
        }

        return true;  // If no mismatch was found, it's a palindrome
    }
};

