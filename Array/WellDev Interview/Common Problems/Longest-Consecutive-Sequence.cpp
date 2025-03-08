#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();  // Step 1: Get the size of the array
        if (n == 0)  // If the array is empty, there is no consecutive sequence
            return 0;

        int longest = 1;  // Step 2: Initialize the longest sequence length
        unordered_set<int> st;  // Step 3: Create a hash set to store unique numbers
        
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);  // Step 4: Insert all elements into the set
        }

        for (auto it : st) {  // Step 5: Iterate over each element in the set
            if (st.find(it - 1) == st.end()) {  // Step 6: Check if it is the start of a sequence
                int cnt = 1;  // Initialize the count of the current sequence
                int x = it;  // Start with the current element

                while (st.find(x + 1) != st.end()) {  // Step 7: Continue the sequence if the next element exists
                    x = x + 1;
                    cnt++;  // Increment the count of the sequence
                }

                longest = max(longest, cnt);  // Step 8: Update the longest sequence length
            }
        }
        
        return longest;  // Step 9: Return the maximum length of the consecutive sequence
    }
};


class Solution {
public:
    // Helper function to check if an element x exists in the array
    bool ls(vector<int> nums, int x) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                return true;  // If found, return true
            }
        }
        return false;  // If not found, return false
    }

    // Function to find the longest consecutive sequence
    int longestConsecutive(vector<int>& nums) {
        int maxCnt = 0;  // Initialize the maximum length of the sequence
        for (int i = 0; i < nums.size(); i++) {  // Loop through each element
            int cnt = 1;  // Start with a count of 1 for the current number
            int x = nums[i];  // Initialize x to the current number
            while (ls(nums, x + 1) == true) {  // Check if the next consecutive number exists
                x++;  // Increment x to the next consecutive number
                cnt++;  // Increment the count for the sequence
            }
            maxCnt = max(maxCnt, cnt);  // Update the maximum count if the current sequence is longer
        }
        return maxCnt;  // Return the maximum length of the consecutive sequence
    }
};
    