#include<bits/stdc++.h>
using namespace std;

//? Contains Duplicate
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// Input: nums = [1,2,3,1]
// Output: true

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

//? Contains Duplicate II
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
// Input: nums = [1,2,3,1], k = 3
// Output: true

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end())
                return true;
            seen.insert(nums[i]);
            if (seen.size() > k)
                seen.erase(nums[i - k]);
        }
        return false;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(min(n, k))

//? Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2]

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

//? Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number.
// Input: nums = [1,3,4,2,2]
// Output: 2

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return {};
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

//? Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Input: s = "anagram", t = "nagaram"
// Output: true

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for (auto x : mp) {
            if (x.second != 0) {
                return false;
            }
        }
        return true;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

//? Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto x : mp) {
            res.push_back(x.second);
        }
        return res;
    }
};
// Time Complexity: O(n * klogk)
// Space Complexity: O(n)

//? Valid Palindrome
// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// Input: s = "A man, a plan, a canal: Panama"
// Output: true

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
// Time Complexity: O(n)
// Space Complexity: O(n)

//? Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int more = target - nums[i];
            if (mp.find(more) != mp.end()) {
                return {mp[more], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)

//? Two Sum II - Input array is sorted
// Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int total = numbers[left] + numbers[right];
            if (total == target) {
                return {left + 1, right + 1};
            } else if (total < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

//? Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Input: nums = [3,0,1]
// Output: 2

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int totalSum = (n + 1) * n / 2;

        return totalSum - sum;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = 0;
        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            xr = xr xor i xor nums[i];
        }

        // for (int i = 0; i <= nums.size(); i++) {
        //     xr = xr xor i;
        // }

        return xr xor i;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

//? Missing and Repeating
class Solution {
public:
    vector<int> findTwoElement(vector<int>& a) {
        int n = a.size(); // size of the array
        int repeating = -1, missing = -1;
    
        //Find the repeating and missing number:
        for (int i = 1; i <= n; i++) {
            //Count the occurrences:
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == i) cnt++;
            }
    
            if (cnt == 2) repeating = i;
            else if (cnt == 0) missing = i;
    
            if (repeating != -1 && missing != -1)
                break;
        }
        return {repeating, missing};
    }
};
  

//? Longest Conservative Subsequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// Input: nums = [100,4,200,1,3,2]
// Output: 4

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
// Time Complexity: 
// Space Complexity:

class Solution {
public:
    bool ls(vector<int> nums, int x) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int maxCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 1;
            int x = nums[i];
            while (ls(nums, x + 1) == true) {
                x++;
                cnt++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};


//? Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};

//? Longest Subarray with Sum K
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSum; // HashMap to store sum -> index
        int sum = 0, longest = 0;
    
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
    
            if(sum == k) {
                longest = i + 1;
            }
    
            if(prefixSum.find(sum - k) != prefixSum.end()) {
                longest = max(longest, i - prefixSum[sum - k]);
            }
    
            if(prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }
        return longest;
    }
};

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
        int maxFreq = 0, start = 0, maxLen = 0;
        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i] - 'A']);

            if ((i - start + 1) - maxFreq > k) {
                freq[s[start] - 'A']--;
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

//? Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSum = max(nums[i], nums[i] + maxSum);
            result = max(result, maxSum);
        }
        return result;
    }
};

//? Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
                int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }
};

//? Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//? Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int i=0; i<nums.size(); i++){
            xr = xr xor nums[i];
        }
        return xr;
    }
};

//? Single Element in Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xr = xr xor nums[i];
        }

        return xr;
    }
};

//? Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

//? Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0, jumps = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);

            if (i == end) {
                jumps++;
                end = maxReach;
            }
        }
        return jumps;
    }
};

//? Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

//? Check if Array is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                cnt++;
            }
            if (cnt > 1) {
                return false;
            }
        }
        return true;
    }
};

//? Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 and nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

//? Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
            else if (nums[i] == 2)
                two++;
        }

        for (int i = 0; i < zero; i++) {
            nums[i] = 0;
        }
        for (int i = zero; i < zero + one; i++) {
            nums[i] = 1;
        }

        for (int i = zero + one; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) { 
        sort(nums.begin(), nums.end()); 
    }
};

//? Search in Rotated and Sorted Array - I
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

//? Search in Rotated and Sorted Array - II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};
    
//? Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // 🔹 Traverse the entire matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) return true;
            }
        }

        return false;
    }
};

//? First and Last Position in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return {first, last};
    }
};

//? Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        vector<pair<int, int>> result;
        for (auto it : mpp) {
            result.push_back({it.second, it.first});
        }
        sort(result.rbegin(), result.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(result[i].second);
        }
        return ans;
    }
};

//? Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};

//? Move Zeros to End
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            nums[i] = ans[i];
        }

        for (int i = ans.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

//? Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
            if (cnt > nums.size() / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};

//? Container with Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
