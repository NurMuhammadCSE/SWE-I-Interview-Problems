#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i = n - 1; i >= 0; i--) {
        while(st.top() != -1 and st.top() >= arr[i]) {
            st.pop();
        }
        ans[i] = st.top(); // The next smaller element
        st.push(arr[i]); // Push current index to stack
    }

    return ans;
}
