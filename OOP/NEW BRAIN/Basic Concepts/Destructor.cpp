/*
Destructor হলো একটি বিশেষ মেথড যা অবজেক্ট ধ্বংস হওয়ার সময় (object destroy / scope থেকে বেরিয়ে গেলে) স্বয়ংক্রিয়ভাবে একবার কল হয় এবং রিসোর্স (মেমরি, ফাইল, কানেকশন ইত্যাদি) মুক্ত করে দেয়।
*/

#include <iostream>
using namespace std;

class Student {
public:
    string name;

    Student(string n) {
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Student s1("Nur");

    {
        Student s2("Hasan");  // Constructor call
    } // s2 এর scope শেষ, Destructor call হবে

    cout << "End of main." << endl;
}
