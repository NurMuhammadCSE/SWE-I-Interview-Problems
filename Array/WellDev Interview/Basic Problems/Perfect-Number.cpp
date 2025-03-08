#include<bits/stdc++.h>
using namespace std;

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


class Solution {
public:
    bool isPerfectNumber(int n) {
        int sum = 0;
        for(int i=1; i<n-1; i++){
            if(n % i == 0){
                sum += i;
            }
        }
        
        return sum == n;
    }
};

// Function to check if the number is perfect
bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}


class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;

        int sum = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i)
                    sum += num / i;
            }
        }
        return sum == num;
    }
};

class Solution {
public:
    bool isPerfectNumber(int n) {
        int sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0)
                if (i * i == n || i == 1)
                    sum = sum + i;
                else
                    sum = sum + i + n / i;
        }
        if (sum == n)
            return true;
        else
            return false;
    }
};
    


int main(){
    int n = 6;
    Solution s;
    cout<< s.isPerfectNumber(n)<<endl;
    return 0;
}