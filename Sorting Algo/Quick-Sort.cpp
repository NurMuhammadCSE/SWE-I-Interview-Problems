#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for(int j=start; j<end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[end], arr[i]);
    return i;
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int pick = partition(arr, start, end);
        quickSort(arr, start, pick - 1);
        quickSort(arr, pick + 1, end);
    }
}

int main(){
    vector<int> arr = {5,2,6,4,1,3};
    quickSort(arr, 0, arr.size());

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
Time Complexity: Best = Average: O(n log n) and Worst Case: O(n^2)
Space Complexity: O(1)
*/