#include<bits/stdc++.h>
using namespace std;

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

int countDigit(long long x) {
    // long long cnt = 0;
    // while(x > 0){
    //     x /= 10;
    //     cnt++;
    // }
    // return cnt;

    long long cnt = (int)(log10(x) + 1);
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout << numberOfDigits(n);
    return 0;
}