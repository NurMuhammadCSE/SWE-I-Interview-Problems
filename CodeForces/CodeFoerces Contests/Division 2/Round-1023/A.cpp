#include <iostream>
#include <vector>
#include <numeric> // for gcd
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        bool found = false;
        // Try different partitions
        for (int i = 1; i < n; ++i) {
            // Group 1: a[0..i-1]
            // Group 2: a[i..n-1]
            int gcd1 = a[0];
            for (int j = 1; j < i; ++j)
                gcd1 = gcd(gcd1, a[j]);

            int gcd2 = a[i];
            for (int j = i + 1; j < n; ++j)
                gcd2 = gcd(gcd2, a[j]);

            if (gcd1 != gcd2) {
                cout << "Yes\n";
                for (int j = 0; j < n; ++j)
                    cout << (j < i ? 1 : 2) << " ";
                cout << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "No\n";
    }
    return 0;
}
