#include<bits/stdc++.h>
using namespace std;

/*Function to find frequency of x
 * x : element whose frequency is to be found
 * arr : input vector
 */
class Solution {
public:
    int findFrequency(vector<int> arr, int x) {
        unordered_map<int, int> freq;
        for(auto num : arr){
            freq[num]++;
        }
        
        for(auto it : freq){
            if(x == it.first){
                return it.second;
            }
        }
        return 0;
    }
};

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Solution obj;
    cout << obj.findFrequency(arr, x);
    return 0;
}