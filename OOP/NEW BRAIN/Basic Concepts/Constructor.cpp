/*
Constructor হলো ক্লাসের বিশেষ ফাংশন, যা অবজেক্ট তৈরি করার সময় একবারই স্বয়ংক্রিয়ভাবে (Automatically) কল হয়।
এর কাজ হলো অবজেক্টের প্রপার্টিগুলোর প্রাথমিক মান (initialization) নির্ধারণ করে দেওয়া।

✅ কনস্ট্রাক্টরের বৈশিষ্ট্য:
বিষয়	ব্যাখ্যা
🔄 কল হয় স্বয়ংক্রিয়ভাবে	অবজেক্ট তৈরি হলেই
⚙️ নাম হয় ক্লাসের নামের মতো	কোন Return type থাকে না
🔁 Overload করা যায়	একাধিক কনস্ট্রাক্টর রাখা যায়
🛠️ ডিফল্ট বা প্যারামিটারসহ হতে পারে constructor overloading
*/

#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// ✅ Default Constructor উদাহরণ:
class Car {
public:
    string brand;

    Car() {
        brand = "Default Brand";
    }
};

// ✅ Parameterized Constructor উদাহরণ:
class Bike {
public:
    string model;
    int year;

    Bike(string m, int y) {
        model = m;
        year = y;
    }

    void show() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};

// ✅ Copy Constructor উদাহরণ:
class Person {
public:
    string name;
    int age;

    // Parameterized Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    // Copy Constructor
    Person(const Person &p) {
        name = p.name;
        age = p.age;
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    void info() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Box {
public:
    int width;

    Box() {
        width = 0;
    }

    Box(int w) {
        width = w;
    }
};

class StudentTwo {
public:
    string name;
    int age;

    // Parameterized Constructor
    StudentTwo(string n, int a) {
        name = n;
        age = a;
    }

    // ✅ Copy Constructor
    StudentTwo(const StudentTwo &s) {
        name = s.name;
        age = s.age;
        cout << "Copy constructor called!" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};


int main() {
    Student s1("Nur", 22);     // constructor auto call হচ্ছে
    Student s2("Zakir", 30);

    s1.display();  // Output: Name: Nur, Age: 22
    s2.display();  // Output: Name: Zakir, Age: 20

    Car car1;  // Default constructor call
    cout << "Car brand: " << car1.brand << endl;  // Output: Default Brand

    Bike bike1("Yamaha", 2022);  // Parameterized constructor call
    bike1.show();  // Output: Model: Yamaha, Year: 2022

    Person p1("Alice", 25);
    Person p2 = p1;  // Copy constructor call
    p2.info();  // Output: Name: Alice, Age: 25

    Box box1;  // Default constructor call
    Box box2(10);  // Parameterized constructor call
    cout << "Box1 width: " << box1.width << endl;  // Output: Box1 width: 0
    cout << "Box2 width: " << box2.width << endl;  // Output: Box2 width: 10

    StudentTwo student1("John", 20);
    StudentTwo student2 = student1;  // Copy constructor call
    student1.display();  // Output: Name: John, Age: 20
    student2.display();  // Output: Name: John, Age: 20
}


/*
🎯 মনে রাখার সহজ সূত্র:
"Constructor মানেই হচ্ছে অবজেক্ট তৈরি হতেই যেটা স্বয়ংক্রিয়ভাবে রান হয় এবং প্রপার্টি সেট করে দেয়।"

🔚 রিক্যাপ:
Constructor = Special function
Object তৈরি হলেই কল হয়
নাম = ক্লাসের নাম
Return টাইপ = নাই
Overload করা যায়
*/