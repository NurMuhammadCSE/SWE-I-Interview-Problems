// Class is a blueprint / template for creating objects.
// Class is a user-defined data type that can contain data members and member functions.
// Class is a collection of data members and member functions.
// class is the only logical representation of an object.
// A class is a group of objects that share common properties and behaviors.

#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    // Data members => attributes, properties
    // Member variables
    string name;
    int age;
    int id;

    // Member function => Method
    void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};
// The class Student has three data members: name, age, and id.
// It also has a member function displayInfo() that prints the student's information.


class Car {
public:
    string brand;
    int year;

    void drive() {
        cout << "Driving..." << endl;
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};
// The class Car has two data members: brand and year.
// It also has a member function drive() that simulates driving the car.


class Human {
public:
    string name;
    int age;

    void speak() {
        cout << "Hello! My name is " << name << endl;
        cout << "I am " << age << " years old." << endl;
    }
};
// The class Human has two data members: name and age.
// It also has a member function speak() that prints a greeting message.


int main(){
    Student student1; // Creating an object of class Student
    student1.name = "John Doe";
    student1.age = 20;
    student1.id = 12345;
    student1.displayInfo(); // Calling member function to display information

    Car car1; // Creating an object of class Car
    car1.brand = "Toyota";
    car1.year = 2020;
    car1.drive(); // Calling member function to simulate driving the car

    Human human1; // Creating an object of class Human
    human1.name = "Alice";
    human1.age = 30;
    human1.speak(); // Calling member function to print greeting message

    return 0;
}

/*
🧱 ক্লাস (Class) কী?
ক্লাস হচ্ছে অবজেক্ট তৈরি করার জন্য একটা ব্লুপ্রিন্ট বা খসড়া নকশা (Template)।
এটা হলো এমন একটা কাঠামো যেখানে তুমি কী কী ডেটা (Property/Attribute) আর কী কী কাজ (Method/Function) থাকবে — সেটা নির্ধারণ করে দাও।

🧠 বাস্তব উদাহরণ:
ধরো, তুমি একটা “মানুষ” নিয়ে কাজ করতে চাও — তার নাম, বয়স, কী করতে পারে এইসব জানাতে চাও।

তাহলে তুমি একটা Human নামের ক্লাস বানাবে। সেটাতে থাকবে:
বৈশিষ্ট্য (Attributes): যেমন name, age
আচরণ (Behaviors): যেমন speak(), walk()

ক্লাস হচ্ছে এমন একটি ইউজার-ডিফাইন্ড ডেটা টাইপ যা ভ্যারিয়েবল (Property) এবং ফাংশন (Method) এর সমন্বয়ে গঠিত এবং এর থেকে অবজেক্ট তৈরি করা হয়।

✅ মনে রাখার রিক্যাপ:
ক্লাস = নকশা
অবজেক্ট = সেই নকশা দিয়ে বানানো জিনিস
ক্লাস-এর ভিতরে ডেটা + ফাংশন = একটা ইউনিট
কোড Reusability, Structure, এবং Maintainability এর জন্য খুবই গুরুত্বপূর্ণ
*/