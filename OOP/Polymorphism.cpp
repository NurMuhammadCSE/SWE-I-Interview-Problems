#include<bits/stdc++.h>
using namespace std;

// Method Overloading
class Mathematics{
public:
    void add(int a, int b){
        cout << "Sum: " << a + b << endl;
    }

    void add(int a, int b, int c){
        cout << "Sum: " << a + b + c << endl;
    }
};

// Method Overriding
class Math{
public:
    virtual void add(int a, int b){
        cout << "Sum: " << a + b << endl;
    }
};

class Math2: public Math{
public:
    void add(double a, double b){
        cout << "Sum: " << a + b << endl;
    }
};


class Parent{
public:
    virtual void show(){
        cout << "Parent" << endl;
    }
};

class Child: public Parent{
public:
    void show() override{
        cout << "Child" << endl;
    }
};

int main() {
    // Mathematics m1;
    // m1.add(10, 20);
    // m1.add(10, 20, 30);

    // Math2 m2;
    // m2.add(10, 20);
    // m2.add(10.5, 20.5);

    Parent *p;
    Child c;
    p = &c;
    p->show();

    Parent* p1 = new Child();
    p1->show();

    return 0;
}