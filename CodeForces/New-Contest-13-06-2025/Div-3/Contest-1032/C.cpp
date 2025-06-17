#include <bits/stdc++.h>
using namespace std;

int getMax(const vector<vector<int>>& mat) {
    int mx = 0;
    for (auto& row : mat)
        for (int val : row)
            mx = max(mx, val);
    return mx;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        int mx = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                mx = max(mx, a[i][j]);
            }

        // সেলগুলো বের করি যেখানে maximum আছে
        vector<pair<int, int>> maxCells;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == mx)
                    maxCells.emplace_back(i, j);

        int ans = INT_MAX;

        for (auto& [r, c] : maxCells) {
            vector<vector<int>> temp = a;

            // রো `r` এর সব উপাদান -1 করো
            for (int j = 0; j < m; ++j) temp[r][j]--;

            // কলাম `c` এর সব উপাদান -1 করো
            for (int i = 0; i < n; ++i) if (i != r) temp[i][c]--;

            // এবার নতুন matrix এর মধ্যে সর্বোচ্চ সংখ্যাটা বের করো
            int localMax = getMax(temp);
            ans = min(ans, localMax);
        }

        cout << ans << '\n';
    }

    return 0;
}
