#include<bits/stdc++.h>
using namespace std;

class Teacher{
public:
    int id;
    string name;
    string dept;
    string subject;

    Teacher(){
        cout << "Default Constructor" << endl;
    }
};

int main(){
    Teacher t1;
    t1.id = 101;
    t1.dept = "CSE";
    t1.name = "Devid Miller";
    t1.subject = "DSA";

    cout << t1.id << endl;
    cout << t1.dept << endl;
    cout << t1.subject << endl;
    cout << t1.name << endl;
}