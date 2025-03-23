#include<bits/stdc++.h>
using namespace std;

class Student{
private:
    string id;
    int salary;

    void hideSalary(){
        this->salary = salary;
    }

public:
    string name;
    int age;
    int roll;

    void show(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll: " << roll << endl;
    }

    void setSalary(int salary){
        this->salary = salary;
    }

    int getSalary(){
        hideSalary();
        return salary;
    }
};

int main() {
    Student s1; // s1 is an object of class Student
    s1.name = "John";
    s1.age = 20;
    s1.roll = 101;

    s1.show(); // calling the show() method of the object s1
    s1.setSalary(50000);
    s1.getSalary();

    return 0;
}   