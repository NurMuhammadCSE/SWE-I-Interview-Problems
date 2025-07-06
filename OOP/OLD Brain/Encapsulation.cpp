#include<bits/stdc++.h>
using namespace std;

class Student{
private:
    string id;
    int salary;

public:
    string name;
    int age;
    int roll;

    void show(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll: " << roll << endl;
    }

    // Getter Methods
    void setId(string id){
        this->id = id;
    }
    void setSalary(int salary){
        this->salary = salary;
    }

    // Setter Methods
    string getId(){
        return id;
    }

    int getSalary(){
        return salary;
    }
};

int main() {
    Student s1; // s1 is an object of class Student
    s1.name = "John";
    s1.age = 20;
    s1.roll = 101;

    s1.show(); // calling the show() method of the object s1
    s1.setId("1234");
    s1.setSalary(50000);

    cout << "ID: " << s1.getId() << endl;
    cout << "Salary: " << s1.getSalary() << endl;

    return 0;
}