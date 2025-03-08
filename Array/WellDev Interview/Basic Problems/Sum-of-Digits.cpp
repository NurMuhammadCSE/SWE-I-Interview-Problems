#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n;
    cin >> n;
    Solution obj;
    cout << obj.sumOfDigits(n);
    return 0;
}