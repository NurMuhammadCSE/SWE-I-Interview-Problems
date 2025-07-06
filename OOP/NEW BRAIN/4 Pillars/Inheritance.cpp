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
