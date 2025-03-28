#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        if(k >= 2){
            cout << "Yes" << endl;
        }else{
            vector<int> sortedArr = a;
            sort(sortedArr.begin(), sortedArr.end());
            if(sortedArr == a){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}