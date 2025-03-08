#include<bits/stdc++.h>
using namespace std;


//? For Small Numbers
class Solution {
public:
    int factorialHelper(int n) {
        if(n == 0){
            return 1;
        }
        return n * factorialHelper(n - 1);
    }
    
    vector<int> factorial(int n) {
        vector<int> result;
        int fact = factorialHelper(n);
        
        while(fact){
            int ld = fact % 10;
            fact /= 10;
            result.push_back(ld);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//? For Large Numbers
class Solution {
public:
    vector<int> factorial(int n) {
        vector<int> result;
        result.push_back(1); // 1! = 1 সেট করে শুরু করা

        for (int num = 2; num <= n; num++) {
            int carry = 0;

            // প্রতিটি সংখ্যার সাথে আগের factorial গুণ করা
            for (int i = 0; i < result.size(); i++) {
                int product = result[i] * num + carry;
                result[i] = product % 10;  // শুধুমাত্র বর্তমান digit সংরক্ষণ
                carry = product / 10;      // বাকি অংশ carry হয়ে যাবে
            }

            // যদি আরও carry থেকে যায়, তাহলে সেটি result-এ যোগ করবো
            while (carry) {
                result.push_back(carry % 10);
                carry /= 10;
            }
        }

        // ভেক্টর উল্টিয়ে দিতে হবে, কারণ আমরা ছোট সংখ্যা আগে যোগ করেছি
        reverse(result.begin(), result.end());

        return result;
    }
};
  

int main(){
    int n;
    cin >> n;
    Solution obj;
    vector<int> result = obj.factorial(n);
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
    }
    return 0;
}