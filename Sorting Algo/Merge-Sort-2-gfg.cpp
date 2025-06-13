#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  void merge(vector<int>& arr, int l, int mid, int r){
      vector<int> temp;
      int i = l;
      int j = mid + 1;
      
      while(i <= mid and j <= r){
          if(arr[i] <= arr[j]){
              temp.push_back(arr[i++]);
          }else{
              temp.push_back(arr[j++]);
          }
      }
      
      while(i <= mid){
          temp.push_back(arr[i++]);
      }
      
      while(j <= r){
          temp.push_back(arr[j++]);
      }
      
      for(int k=l; k<=r; k++){
          arr[k] = temp[k-l];
      }
  }
  
    void mergeSort(vector<int>& arr, int l, int r) {
       
      if(l >= r) {
          return;
      }
      int mid = l + (r - l) / 2;
      
      mergeSort(arr, l, mid);
      mergeSort(arr, mid + 1, r);
      
      merge(arr, l, mid, r);
        
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}