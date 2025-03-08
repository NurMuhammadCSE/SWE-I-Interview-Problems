#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumOfSeries(long long n) {
        // long long sum = 0;
        // for(long long i=1; i<=n; i++){
        //     sum += pow(i *  i * i);
        // }
        long long sum = (n * (n+1)/2) * (n * (n+1)/2);
        return sum;
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.sumOfSeries(n) << endl;
    }
    return 0;
}
