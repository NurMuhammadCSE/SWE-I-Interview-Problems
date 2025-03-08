#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

void rightRotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i]; // নতুন ইনডেক্স এ সেট করা
    }
    
    arr = temp; // আসল অ্যারেতে সেট করা
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int d = 2;
    Solution s;
    s.rotate(arr, d);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    rightRotate(arr, k);
    
    for (int num : arr) {
        cout << num << " ";
    }
    
    return 0;
}