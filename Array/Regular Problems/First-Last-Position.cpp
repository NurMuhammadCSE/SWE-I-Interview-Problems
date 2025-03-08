
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int first = -1, last = -1;
    
            // পুরো অ্যারের উপর লুপ চালিয়ে প্রথম ও শেষ অবস্থান খোঁজা
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    if (first == -1) { // প্রথম উপস্থিতি সংরক্ষণ করা
                        first = i;
                    }
                    last = i; // প্রতিবার আপডেট করবো যেন শেষ উপস্থিতি পাওয়া যায়
                }
            }
    
            return {first, last};
        }
    };
    