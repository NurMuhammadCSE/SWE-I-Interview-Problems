#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];

        int mini = x[0];
        int maxi = x[n - 1];

        int steps = (maxi - mini) + min(abs(s - mini), abs(s - maxi));
        cout << steps << "\n";
    }

    return 0;
}
