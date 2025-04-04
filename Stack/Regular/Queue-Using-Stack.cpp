#include <bits/stdc++.h>
using namespace std;

class MyQueue{
    stack<int> input, output;
public:
    void push(int x){
        input.push(x);
    }

    int pop(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int topElement = output.top();
        output.pop();
        return topElement;
    }

    int peek(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty(){
        return input.empty() and output.empty();
    }
};

int main(){
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << endl;
    cout << q.peek() << endl; // Top
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    cout << q.empty() << endl;

}