#include <iostream>
using namespace std;

class Walkable {
public:
    virtual void walk() = 0;
};

class Flyable {
public:
    virtual void fly() = 0;
};

class Dog : public Walkable {
public:
    void walk() override {
        cout << "Dog is walking" << endl;
    }
};

class Bird : public Walkable, public Flyable {
public:
    void walk() override {
        cout << "Bird is walking" << endl;
    }

    void fly() override {
        cout << "Bird is flying" << endl;
    }
};

int main() {
    Dog dog;
    dog.walk();

    Bird bird;
    bird.walk();
    bird.fly();

    return 0;
}
