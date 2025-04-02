#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        
        // q1 থেকে সব এলিমেন্ট q2-তে রেখে, শেষের এলিমেন্ট বাদ দিচ্ছি
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop(); // লাস্ট এলিমেন্ট রিমুভ

        // q1 ও q2 swap করে নিচ্ছি
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(q1.front());
        q1.pop();

        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl; // 30
    s.pop();

    cout << s.top() << endl; // 20
    s.pop();

    cout << s.top() << endl; // 10
    s.pop();

    cout << s.empty() << endl; // 1 (true)

    return 0;
}
