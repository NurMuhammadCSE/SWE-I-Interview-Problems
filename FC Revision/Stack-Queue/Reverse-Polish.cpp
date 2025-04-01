#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int op2 = st.top();
                st.pop();

                int op1 = st.top();
                st.pop();

                if (t == "+") {
                    op1 = op1 + op2;
                } else if (t == "-") {
                    op1 = op1 - op2;
                } else if (t == "*") {
                    op1 = op1 * op2;
                } else if (t == "/") {
                    op1 = op1 / op2;
                }
                st.push(op1);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};