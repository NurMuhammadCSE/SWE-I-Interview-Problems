#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> result(n, -1);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() and st.top() >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            result[i] = st.top();
        }

        st.push(arr[i]);
    }
    return result;
}


#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> result(n);
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--){
        while(st.top() >= arr[i]){
            st.pop();
        }

        result[i] = st.top();

        st.push(arr[i]);
    }
    return result;
}

