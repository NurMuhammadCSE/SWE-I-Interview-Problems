#include <bits/stdc++.h>
using namespace std;

// 🟢 1️⃣ Recursive Approach (Naive – Exponential Time Complexity)
int climbingStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (n <= n) {
        return n;
    }

    return climbingStairs(n - 1) + climbingStairs(n - 2);
}
/*
⏳ Time & Space Complexity:
Time Complexity: O(2^N) (Exponential ❌)
Space Complexity: O(N) (Recursive Stack)
*/

// 🟢 2️⃣ Memoization Approach (Top-Down DP)
class Solution {
public:
    int climbHelper(int n, vector<int>& dp) {
        if (n <= 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = climbHelper(n - 1, dp) + climbHelper(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climbHelper(n, dp);
    }
};
/*
⏳ Time & Space Complexity:
Time Complexity: O(N) (Optimized ✅)
Space Complexity: O(N) (Recursive Stack + dp[] array)
✔ সুবিধা:
আগের কলগুলো dp[] অ্যারেতে সংরক্ষণ করা হয়, তাই ডুপ্লিকেট কাজ হয় না।
Recursive Call Stack এর কারণে Extra O(N) Space লাগে।
*/

// 🟢 3️⃣ Iterative DP Approach (Bottom-Up)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
/*
⏳ Time & Space Complexity:
Time Complexity: O(N) ✅
Space Complexity: O(N) (dp[] অ্যারের জন্য)
*/

// 🟢 4️⃣ Space Optimized Iterative Approach (Best Solution)
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int a = 1, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
/*
⏳ Time & Space Complexity:
Time Complexity: O(N) ✅
Space Complexity: O(1) ✅ (Only 2 variables used)
✔ dp[] অ্যারে লাগেনি, তাই O(1) Space!
✔ সবচেয়ে ভালো এবং Optimal Solution! 🚀
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};

/*
⏳ Time & Space Complexity:
Time Complexity: O(N) ✅
Space Complexity: O(1) ✅ (Only 2 variables used)
✔ dp[] অ্যারে লাগেনি, তাই O(1) Space!
✔ সবচেয়ে ভালো এবং Optimal Solution! 🚀
*/

int main() {
    int n;
    cin >> n;

    cout << climbingStairs(n) << endl;
    return 0;
}