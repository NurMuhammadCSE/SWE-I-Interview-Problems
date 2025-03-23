#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int age;
    int roll;

    void show(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll: " << roll << endl;
    }
};

int main() {
    Student s1; // s1 is an object of class Student
    s1.name = "John";
    s1.age = 20;
    s1.roll = 101;

    s1.show(); // calling the show() method of the object s1
    return 0;
}