#include <bits/stdc++.h>
using namespace std;

// Method Overloading Example
// Method overloading allows the same function name to be used with different parameter types or numbers of parameters.
class Math {
public:
    void sum(int a, int b) {
        cout << "Sum: " << a + b << endl;
    }

    void sum(double a, double b) {
        cout << "Sum (double): " << a + b << endl;
    }

    void sum(int a, int b, int c) {
        cout << "Sum (three numbers): " << a + b + c << endl;
    }
};

class Print {
public:
    void show(int a) {
        cout << "Integer: " << a << endl;
    }

    void show(string s) {
        cout << "String: " << s << endl;
    }
};

// Method Overriding Example
class Parent {
public:
    virtual void show() {
        cout << "This is Parent Class" << endl;
    }
};

class Child : public Parent {
public:
    void show() override {
        cout << "This is Child Class" << endl;
    }
};

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

// Virtual Functions Example
// Virtual functions allow derived classes to override base class methods, enabling polymorphic behavior.

class Base {
public:
    virtual void show() {
        cout << "Base Class" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived Class" << endl;
    }
};


int main() {
    Math mathObj;
    mathObj.sum(5, 10);
    mathObj.sum(5.5, 2.2);
    mathObj.sum(1, 2, 3);

    Print printObj;
    printObj.show(5);        // Integer: 5
    printObj.show("Nur");    // String: Nur

    Parent *p;
    Child c;
    p = &c;
    p->show(); // Derived Class-এর ফাংশন কল হবে (Run-time-এ ঠিক হবে)

    Animal* a;
    Dog d;
    a = &d;
    a->speak(); // Output: Dog barks (NOT Animal speaks!)

    Base *b;
    Derived dd;
    b = &dd;
    b->show(); // Derived Class-এর ফাংশন কল হবে

    return 0;
}
