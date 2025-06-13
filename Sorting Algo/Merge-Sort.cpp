#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    vector<int> temp;
    int i = start;
    int j = mid+1;

    while (i <= mid and j <= end)
    {
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int k=0; k<temp.size(); k++){
        arr[k+start] = temp[k];
    }
    
}

void mergeSort(vector<int> &arr, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid); // Left Half
        mergeSort(arr, mid+1, end); // Right Half

        merge(arr, start, mid, end);
    }
}

int main(){
    vector<int> arr = {12, 31, 8, 17, 32};

    mergeSort(arr, 0, arr.size());

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
    Time Complexity: Best = Average = Worst: O(n log n)
    Space Complexity: O(n)
*/