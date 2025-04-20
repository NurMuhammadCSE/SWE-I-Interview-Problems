#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // test case সংখ্যা
    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        // আমরা জানি: r - l = n, তাই length = n + 1
        // m-th দিনে length হবে m + 1

        // সংক্রমিত segment এর শুরু l থেকে m দূরে শুরু করি
        int l_prime = l + (n - m);
        int r_prime = l_prime + m;

        cout << l_prime << " " << r_prime << endl;
    }
    return 0;
}
