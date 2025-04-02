#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q;

public:
    // Stack-এর push অপারেশন (O(n) complexity)
    void push(int x)
    {
        q.push(x);
        int size = q.size();

        for (int i = 0; i < size - 1; i++)
        {
            q.push(q.front()); // সামনের এলিমেন্ট পেছনে পাঠাচ্ছি
            q.pop();           // সামনের এলিমেন্ট সরিয়ে দিচ্ছি
        }
    }

    // Stack-এর pop অপারেশন (O(1) complexity)
    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is Empty";
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.empty() << endl;
}