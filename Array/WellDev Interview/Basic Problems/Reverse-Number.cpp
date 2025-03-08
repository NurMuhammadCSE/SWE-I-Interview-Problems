#include<bits/stdc++.h>
using namespace std;

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
  

int main(){
    int n;
    cin >> n;
    cout << reverseNumber(n);
    return 0;
}