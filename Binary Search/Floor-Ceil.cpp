#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> getFloorAndCeil(int x, vector<int> &arr) {
          int floorVal = -1, ceilVal = -1;
          int l = 0, h = arr.size() - 1;
  
          sort(arr.begin(), arr.end()); // অ্যারে সর্ট করা প্রয়োজন
  
          while (l <= h) {
              int mid = l + (h - l) / 2;
  
              if (arr[mid] == x) {
                  return {x, x}; // যদি x অ্যারেতে থাকে, তাহলে floor এবং ceil একই হবে।
              } else if (arr[mid] < x) {
                  floorVal = arr[mid]; // সম্ভাব্য Floor
                  l = mid + 1;
              } else {
                  ceilVal = arr[mid]; // সম্ভাব্য Ceil
                  h = mid - 1;
              }
          }
  
          return {floorVal, ceilVal};
      }
  };

// Coding Ninjas Solution
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int low = 0, high = n - 1;
    int floorValue = -1, ceilValue = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] <= x) {
            floorValue = a[mid]; 
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] >= x) {
            ceilValue = a[mid]; 
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }

    return {floorValue, ceilValue};
}


class Solution {
    public:
      int findFloor(vector<int>& arr, int x) {
          int l = 0, h = arr.size() - 1, floorVal = -1;
  
          while (l <= h) {
              int mid = l + (h - l) / 2;
  
              if (arr[mid] <= x) {
                  floorVal = arr[mid]; // সম্ভাব্য ফ্লোর সংরক্ষণ
                  l = mid + 1;
              } 
              else {
                  h = mid - 1;
              }
          }
  
          return floorVal; // যদি ফ্লোর না থাকে, -1 রিটার্ন করবো
      }
  };

  
  class Solution {
    public:
  
      int findFloor(vector<int>& arr, int k) {
          if(arr[0] > k){
              return -1;
          }
          for(int i=0; i<arr.size(); i++){
              if(arr[i] > k){
                  return i - 1;
              }
          }
          return arr.size() - 1;
          
      }
  };
  

  
int main() {
    Solution obj;
    vector<int> arr = {2, 8, 10, 15, 16, 20, 25};
    int x = 17;
    vector<int> ans = obj.getFloorAndCeil(x, arr);
    cout << "Floor: " << ans[0] << ", Ceil: " << ans[1] << endl;
    return 0;
}