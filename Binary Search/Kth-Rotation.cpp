#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
    
        // যদি অ্যারে আগেই সাজানো থাকে, তা হলে ঘুরানোর সংখ্যা 0
        if (arr[left] < arr[right]) {
            return 0;
        }
    
        // Binary search to find the pivot point (smallest element)
        while (left <= right) {
            int mid = left + (right - left) / 2;
    
            // Check if mid is the pivot (i.e., arr[mid] > arr[mid + 1])
            if (arr[mid] > arr[mid + 1]) {
                return mid + 1;  // Return the number of rotations
            }
    
            // Check if mid-1 is the pivot
            if (arr[mid] < arr[mid - 1]) {
                return mid;  // Return the number of rotations
            }
    
            // Determine which side of the array to search in
            if (arr[mid] >= arr[left]) {
                left = mid + 1;  // Search the right half
            } else {
                right = mid - 1;  // Search the left half
            }
        }
    
        return 0;  // Array is not rotated
    }

};

int main() {
    Solution solution;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.findKRotation(arr) << endl;
    return 0;
}