// Inheritance allows a child class (called the derived class or child class) to inherit properties and behaviors (attributes and methods) from another parent class (called the base class or parent class). 
// Inheritance is a feature of OOP which allows subclasses to inherit properties and methods from a parent class.
/*
Types of Inheritance:
1. Single Inheritance: A derived class inherits from a single base class.
2. Multiple Inheritance: A derived class inherits from multiple base classes.   
3. Multilevel Inheritance: A derived class inherits from another derived class.
4. Hierarchical Inheritance: Multiple derived classes inherit from a single base class. 
5. Hybrid Inheritance: A combination of two or more types of inheritance.

*/

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark!" << endl;
    }
};
// Another derived class
class Cat : public Animal {
public:
    void meow() {
        cout << "I can meow!" << endl;
    }
};
// Another derived class
class Bird : public Animal {
public:
    void chirp() {
        cout << "I can chirp!" << endl;
    }
};

int main() {
    Dog d;
    d.eat();   // Base class থেকে পাওয়া
    d.bark();  // নিজস্ব function
    
    Cat c;
    c.eat();   // Base class থেকে পাওয়া 
    c.meow();  // নিজস্ব function

    Bird b;
    b.eat();   // Base class থেকে পাওয়া
    b.chirp(); // নিজস্ব function
    
    return 0;
}
