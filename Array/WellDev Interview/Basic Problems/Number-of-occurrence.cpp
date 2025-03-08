#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N), N = size of the given array
// Reason: We are traversing the whole array.

// Space Complexity: O(1) as we are not using any extra space.

// Approach	    Time 	Space
// Brute Force	O(n)	O(1)
//? Partially Correct/Accepted
int count(vector<int>& arr, int n, int x) {
	int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            cnt++;
        }
    }
    return cnt;
}

// Approach	    Time 	Space
// Brute Force	O(n)	O(1)
//? Partially Correct/Accepted
int count(vector<int>& arr, int n, int x) {
    unordered_map<int, int> freq;
    for(auto it: arr){
        freq[it]++;
    }
    return freq[x];
}

// Approach	    Time 	Space
// Brute Force	O(n)	O(1)
//? Partially Correct/Accepted
int count(vector<int>& arr, int n, int x) {
    unordered_map<int, int> freq;
    for(auto it: arr){
        freq[it]++;
    }
    for(auto it: freq){
        if(x == it.first){
            return it.second;
        }
    }
    return 0;
}

// Approach	        Time 	                            Space
// Binary Search  	O(log n) + O(log n) = O(log n)	    O(1)
// Time Complexity: O(2*logN), where N = size of the given array.
// Reason: We are basically using the binary search algorithm twice.

// Space Complexity: O(1) as we are using no extra space.
//* ACCEPTED
int firstPosition(vector<int> &arr, int x){
    int left = 0, right = arr.size() - 1;
    int first = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == x){
            first = mid;
            right = mid - 1;
        }else if(arr[mid] < x){
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return first;
}

int lastPosition(vector<int>& arr, int x){
    int left = 0, right = arr.size() - 1, last = -1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == x){
            last = mid;
            left = mid + 1;
        }else if(arr[mid] < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return last;
}

int count(vector<int>& arr, int n, int x) {
	int first = firstPosition(arr, x);
    if(first == -1) return 0;
    int last = lastPosition(arr, x);
    return (last - first + 1);
}


int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << count(arr, n, x);
    return 0;
}

