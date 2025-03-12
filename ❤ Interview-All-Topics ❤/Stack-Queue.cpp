#include<bits/stdc++.h>
using namespace std;

//? Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty() || s[i] == ')' and st.top() != '(' ||
                    s[i] == '}' and st.top() != '{' ||
                    s[i] == ']' and st.top() != '[') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};


//? Min Stack
class MinStack {
    stack<int> st;
    stack<int> min_st;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);

        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
    }

    void pop() {
        if (!st.empty()) {
            int min = st.top();
            st.pop();

            if (min_st.top() == min) {
                min_st.pop();
            }
        }
    }

    int top() { return st.top(); }

    int getMin() { return min_st.top(); }
};
