#include<bits/stdc++.h>
using namespace std;

void frequency(vector<int> arr){
    unordered_map<int, int> freq;
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    for(auto it : freq){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,2,1,2,3,4,5};
    frequency(arr);
}