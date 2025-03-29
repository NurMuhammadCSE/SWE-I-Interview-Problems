#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 1️⃣ সর্বনিম্ন সংখ্যা বের করো
        int minA = *min_element(a.begin(), a.end());
        
        // 2️⃣ GCD বের করো (প্রথম ভিন্ন সংখ্যা দিয়ে শুরু)
        int gcd = -1;
        for (int i = 0; i < n; i++) {
            int diff = a[i] - minA;
            if (diff > 0) { // 0 বাদ দিতে হবে
                if (gcd == -1) gcd = diff;
                else gcd = __gcd(gcd, diff);
            }
        }
        
        // 3️⃣ উত্তর প্রিন্ট করো
        cout << gcd << endl;
    }

    return 0;
}
