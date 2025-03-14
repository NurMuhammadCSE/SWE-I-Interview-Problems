#include<bits/stdc++.h>
using namespace std;

//? Number of Digits

int numberOfDigits(int n){
    int cnt = 0;
    while (n)
    {
        n /= 10;
        cnt++;
    }
    
    return cnt;
}

int countDigit(long long x) {
    long long cnt = 0;
    while(x){
        x /= 10;
        cnt++;
    }
    return cnt;
}


//? Sum of Digits in a Number
class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while(n){
            int ld = n % 10;
            sum += ld;
            n /= 10;
        }
        return sum;
    }
};


//? Reverse Number

int reverseNumber(int num){
    int rev = 0;
    while (num)
    {
        int ld = num % 10;
        rev = rev * 10 + ld;
        num /= 10;
    }
    
    return rev;
}

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        reverse(arr.begin(), arr.end());
    }      
};



//? Palindrome Number
bool palindrome(int n)
{
    int dup = n;
    int rev = 0;
    while(n > 0){
        int ld = n % 10;
        rev = rev * 10 + ld;
        n /= 10;
    }

    return rev == dup;
}


//? Check Armstrong

bool isArmstrong(int num) {
    int original = num;
	int digits = 0;
	int armstrong = 0;

	while(num){
		num /= 10;
		digits++;
	}
	num = original;
	while(num){
		int ld = num % 10;
		armstrong += pow(ld, digits);
		num /= 10;
	}
	return original == armstrong;
}


//? Fibonacci Number

class Solution {
public:
    int fib(int n) {
        if(n <= 2){
            return n;
        }
        return fib(n-1) + fib(n-2);
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


//? Factorial Number

class Solution {
public:
    int factorial(int n) {
        if(n == 0){
            return 1;
        }
        return n * factorial(n - 1);
    }
};



//? Permutation

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



//? Divisors/Factors of a Number

vector<int> printDivisors(int n){
    vector<int> result;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            result.push_back(i);
        }
    }
    return result;
}


//? Prime Numbers

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}


bool isPrime(int num) {
    if(num <= 1) return false;
    for(int i=2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}



//? GCD

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}


int gcd_brute_force(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}



//? LCM


//? Perfect Number
class Solution {
public:
    bool isPerfectNumber(int n) {
        vector<int> res;
        for(int i=1; i<=n/2; i++){
            if(n % i == 0){
                res.push_back(i);
            }
        }
        
        int sum = 0;
        for(int i=0; i<=res.size()-1; i++){
            sum += res[i];
        }
        
        return n == sum;
    }
};



//? Left Rotate Array

class Solution {
public:
    void leftRotate(vector<int>& nums, int k) {
        k = k % nums.size();  // বড় k থাকলে মোডুলো নিলে সহজ হয়

        reverse(nums.begin(), nums.begin() + k);  // প্রথম k অংশ উল্টানো
        reverse(nums.begin() + k, nums.end());    // বাকি অংশ উল্টানো
        reverse(nums.begin(), nums.end());        // পুরো Array উল্টানো
    }
};
    


//? Right Rotate

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


//? Number of Occurrence



//? Frequency Each Element

void frequency(vector<int> arr){
    unordered_map<int, int> freq;
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    for(auto it : freq){
        cout << it.first << " " << it.second << endl;
    }
}


