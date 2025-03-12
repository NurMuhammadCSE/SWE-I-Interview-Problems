#include<bits/stdc++.h>
using namespace std;

//? Longest Substring without Repeating Characters
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

//? Longest Repeating Character Replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0, maxLen = 0, start = 0;
        int hash[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'A']++;
            maxFreq = max(maxFreq, hash[s[i] - 'A']);

            if ((i - start + 1) - maxFreq > k) {
                hash[s[start] - 'A']--;
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};


//? Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix)) {
                prefix = prefix.substr(0, prefix.size() - 1);
            }
            if (prefix.empty()) {
                return "";
            }
        }
        return prefix;
    }
};


//? Longest Palindromic Substring




//? Valid Anagram
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


//? Valid Palindrome

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


//? Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        
        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end()); // Sorting to find anagram groups
            mpp[sortedStr].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto it : mpp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};


//? FizzBuzz

vector<string> fizzBuzz(int n){
    vector<string> result;
    for(int i=1; i<=n; i++){
        if(i % 3 == 0 and i % 5 == 0){
            result.push_back("FizzBuzz");
        }else if(i % 3 == 0){
            result.push_back("Fizz");
        }else if(i % 5 == 0){
            result.push_back("Buzz");
        }else{
            result.push_back(to_string(i));
        }
    }
    return result;
}


//? Permutations

class Solution {
public:
    void helper(vector<int> &nums, int idx, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            helper(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};


//? Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

//? Reverse String



//? Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty() || s[i] == ')' and st.top() != '(' ||
                    s[i] == '}' and st.top() != '{' ||
                    s[i] == ']' and st.top() != '[') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


