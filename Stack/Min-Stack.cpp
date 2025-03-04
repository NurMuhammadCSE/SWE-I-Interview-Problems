#include<bits/stdc++.h>
using namespace std;

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
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl; // -3
    obj->pop();
    cout << obj->top() << endl; // 0
    cout << obj->getMin() << endl; // -2
    return 0;
}