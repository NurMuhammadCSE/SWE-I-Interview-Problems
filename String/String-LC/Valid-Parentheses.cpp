#include<bits/stdc++.h>
using namespace std;

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

int main() {
    Solution obj;
    string s = "()";
    cout << obj.isValid(s);
    return 0;
}