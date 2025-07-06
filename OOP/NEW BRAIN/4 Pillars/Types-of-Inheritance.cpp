#include <bits/stdc++.h>
using namespace std;

// Hybrid Inheritance Example
#include <iostream>
using namespace std;

// 🔹 Base Class
class A {
public:
    void showA() {
        cout << "Class A" << endl;
    }
};

// 🔸 Class B inherits A
class B : virtual public A {
public:
    void showB() {
        cout << "Class B" << endl;
    }
};

// 🔸 Class C also inherits A
class C : virtual public A {
public:
    void showC() {
        cout << "Class C" << endl;
    }
};

// 🔺 Class D inherits both B and C → Hybrid Inheritance
class D : public B, public C {
public:
    void showD() {
        cout << "Class D" << endl;
    }
};

int main() {
    D obj;

    obj.showA();  // From A (virtual → no ambiguity)
    obj.showB();  // From B
    obj.showC();  // From C
    obj.showD();  // From D

    return 0;
}
