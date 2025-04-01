#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 and arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 and arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (heights.empty())
            return 0;
        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++) {
            int l = heights[i];

            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int maxArea = l * b;
            area = max(area, maxArea);
        }
        return area;
    }
};