#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n <= 2){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};

int main(){
    int n;
    cin >> n;
    Solution obj;
    cout << obj.fib(n);
    return 0;
}