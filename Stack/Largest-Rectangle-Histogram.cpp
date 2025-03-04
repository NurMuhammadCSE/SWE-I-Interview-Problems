#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int minArea = INT_MAX;
            for (int j = i; j < heights.size(); j++) {
                minArea = min(minArea, heights[j]);
                maxArea = max(maxArea, minArea * (j - i + 1));
            }
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}