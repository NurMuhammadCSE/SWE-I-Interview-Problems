#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool knows(int a, int b){
        // The API knows(a, b) returns whether A knows B.
        return true;
    }

    // int celebrity(int n){
    //     stack<int> s;
    //     for(int i = 0; i < n; i++){
    //         s.push(i);
    //     }
    //     while(s.size() > 1){
    //         int a = s.top();
    //         s.pop();
    //         int b = s.top();
    //         s.pop();
    //         if(knows(a, b)){
    //             s.push(b);
    //         }else{
    //             s.push(a);
    //         }
    //     }
    //     int c = s.top();
    //     s.pop();
    //     for(int i = 0; i < n; i++){
    //         if(i != c && (knows(c, i) || !knows(i, c))){
    //             return -1;
    //         }
    //     }
    //     return c;
    // }

    public:
        int findCelebrity(int n){
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(knows(ans, i)){
                ans = i;
            }
        }

        for(int i = 0; i < n; i++){
            if(i != ans && (knows(ans, i) || !knows(i, ans))){
                return -1;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    cout << obj.findCelebrity(4) << "\n";
    return 0;
}