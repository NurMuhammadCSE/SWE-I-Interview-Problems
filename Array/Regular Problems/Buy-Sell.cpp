#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = prices[0];
        for(int i=1; i<prices.size(); i++){
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sol.maxProfit(prices);
    return 0;
}
