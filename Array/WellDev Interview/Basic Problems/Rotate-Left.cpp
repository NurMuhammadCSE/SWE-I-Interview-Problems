#include<bits/stdc++.h>
using namespace std;

vector<int> leftRotate(vector<int> arr, int d){
    int n = arr.size();
    d= d % n;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(arr[(i+d)%n]);
    }
    return result;
}

void leftRotateCourse(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // বড় k হলে মোডুলো নিলে সহজ হবে
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n]; // নতুন ইনডেক্স এ সেট করা
    }
    
    arr = temp; // আসল অ্যারেতে সেট করা
}

class Solution {
public:
    void leftRotate(vector<int>& nums, int k) {
        k = k % nums.size();  // বড় k থাকলে মোডুলো নিলে সহজ হয়

        reverse(nums.begin(), nums.begin() + k);  // প্রথম k অংশ উল্টানো
        reverse(nums.begin() + k, nums.end());    // বাকি অংশ উল্টানো
        reverse(nums.begin(), nums.end());        // পুরো Array উল্টানো
    }
};


int main(){
    vector<int> arr = {1,2,3,4,5};
    int d = 2;
    vector<int> result = leftRotate(arr, d);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    leftRotateCourse(arr, k);
    
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}