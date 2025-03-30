#include<bits/stdc++.h>
using namespace std;

/*
🔹 Problem Statement: Fibonacci Number
তোমাকে একটি সংখ্যা n দেওয়া হবে, এবং তোমাকে nth Fibonacci Number বের করতে হবে।

🔹 Fibonacci Sequence কেমন?
Fibonacci সিরিজের প্রথম দুটি সংখ্যা 0 এবং 1, এরপর প্রতিটি সংখ্যা তার আগের দুটি সংখ্যার যোগফল।
তাহলে Fibonacci সিরিজ হবে:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
F(n)=F(n−1)+F(n−2)
*/
// 1️⃣ Recursive Approach (Without Memoization)
class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
/*
✅ Time Complexity: O(2^n) (Exponential)
❌ Space Complexity: O(n) (Recursion Stack)
*/

// 2️⃣ Dynamic Programming (Tabulation Approach)
class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
/*
✅ Time Complexity: O(n) (Linear)
✅ Space Complexity: O(n) (DP Array)
*/    

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
/*
✅ Time Complexity: O(n)
✅ Space Complexity: O(1) (একটি মাত্র ভেরিয়েবল ব্যবহার করে করা হয়েছে)
*/