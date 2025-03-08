#include<bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n){
    vector<int> result;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> result = printDivisors(n);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}

// int main() {
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++) {
//         if(n % i == 0) {
//             cout << i << " ";
//         }
//     }
//     return 0;
// }