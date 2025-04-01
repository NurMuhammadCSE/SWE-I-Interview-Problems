#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int miss = -1, rep = -1;
        int n = arr.size();
        
        for(int i=1; i<=n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(arr[j] == i){
                    cnt++;
                }
            }
            if(cnt == 2) rep = i;
            else if (cnt == 0) miss = i;
            
            if(miss != -1 and rep != -1){
                break;
            }
        }
        return {rep, miss};
    }
};
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
The time complexity is O(n^2) because we are using a nested loop to count the occurrences of each number in the array, and the space complexity is O(1) because we are using a constant amount of extra space (the variables miss and rep).
This approach is not efficient for large arrays, as it has a quadratic time complexity. A more efficient approach would be to use a hash map or an array to count the occurrences of each number in O(n) time and O(n) space.
*/



class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int miss = -1, rep = -1;
        vector<int> freq(n + 1, 0);
        
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(freq[i] == 2) rep= i;
            if(freq[i] == 0) miss = i;
         }
        
        return {rep, miss};
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
The time complexity is O(n) because we are iterating through the array once to count the occurrences of each number, and then iterating through the frequency array once to find the missing and repeating numbers. The space complexity is O(n) because we are using an additional array of size n+1 to store the frequency of each number.
*/