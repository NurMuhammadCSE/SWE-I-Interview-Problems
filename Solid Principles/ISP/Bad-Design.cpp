#include <iostream>
#include <stdexcept>
using namespace std;

class Animal {
public:
    virtual void walk() = 0;
    virtual void fly() = 0;
};

class Dog : public Animal {
public:
    void walk() override {
        cout << "Dog is walking" << endl;
    }

    void fly() override {
        // Dog তো উড়তে পারে না!
        throw logic_error("Dog can't fly!");
    }
};

int main() {
    Dog dog;
    dog.walk();

    try {
        dog.fly();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
// using interfaces or separating flying animals from non-flying ones.
// This way, we can ensure that all subclasses adhere to the expected behavior without causing runtime errors