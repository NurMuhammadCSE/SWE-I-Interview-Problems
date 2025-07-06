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

class Car{
public:
    string name;
    string model;
    int price;

    void show(){
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Student s1; // s1 is an object of class Student
    s1.name = "John";
    s1.age = 20;
    s1.roll = 101;

    s1.show(); // calling the show() method of the object s1


    Car c1; // c1 is an object of class Car
    c1.name = "BMW";
    c1.model = "X5";
    c1.price = 100000;

    c1.show(); // calling the show() method of the object c1

    return 0;
}