#include <iostream>
using namespace std;

// ✅ Step 1: আলাদা Base class যেটা সবাই করতে পারে
class Bird {
public:
    virtual void makeSound() {
        cout << "Generic bird sound" << endl;
    }
};

// ✅ Step 2: Subclass Sparrow (উড়ে + sound করে)
class Sparrow : public Bird {
public:
    void makeSound() override {
        cout << "Sparrow: Chirp chirp" << endl;
    }
};

// ✅ Step 3: Subclass Ostrich (উড়তে পারে না, কিন্তু sound করতে পারে)
class Ostrich : public Bird {
public:
    void makeSound() override {
        cout << "Ostrich: Boom boom" << endl;
    }
};

// ✅ Step 4: Function that uses Bird safely
void letBirdSpeak(Bird* bird) {
    bird->makeSound();
}

int main() {
    Bird* bird1 = new Sparrow();
    letBirdSpeak(bird1); // ✅ Sparrow: Chirp chirp

    Bird* bird2 = new Ostrich();
    letBirdSpeak(bird2); // ✅ Ostrich: Boom boom

    return 0;
}
// Note: This code adheres to the Liskov Substitution Principle (LSP) because both Sparrow and Ostrich
// can be used interchangeably as Birds without causing unexpected behavior.