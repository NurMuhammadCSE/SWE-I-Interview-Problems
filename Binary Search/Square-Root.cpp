#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int floorSqrt(int n) {
        int l = 0;
        int h = n;
        int ans = -1;
        
        while(l <= h){
            int mid = l + (h-l) / 2;
            
            if(mid * mid == n){
                return mid;
            }else if(mid * mid < n){
                l = mid + 1;
                ans = mid;
            }else{
                h = mid - 1;
            }
        }
        return ans;
    }
};
  
int main() {
    Solution solution;
    int n = 16;
    cout << solution.floorSqrt(n) << endl;
    return 0;
}