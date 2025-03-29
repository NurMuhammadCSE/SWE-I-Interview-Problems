#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> stations(n);
        
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        
        // 0 এবং x যোগ করলাম
        stations.push_back(0);
        stations.push_back(x);
        
        // স্টেশনগুলো সাজিয়ে নিলাম
        sort(stations.begin(), stations.end());
        
        // সর্বোচ্চ গ্যাপ খুঁজে বের করা
        int maxGap = 0;
        for (int i = 1; i < stations.size(); i++) {
            maxGap = max(maxGap, stations[i] - stations[i - 1]);
        }
        
        // সর্বোচ্চ গ্যাপের দ্বিগুণ হবে ট্যাঙ্কের প্রয়োজনীয় ক্ষমতা
        cout << maxGap << endl;
    }
    
    return 0;
}
