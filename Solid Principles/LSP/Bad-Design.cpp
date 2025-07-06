#include <iostream>
#include <stdexcept>
using namespace std;

class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying" << endl;
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        cout << "Sparrow is flying" << endl;
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        // 🛑 LSP ভঙ্গ করা হচ্ছে: উড়তে পারে না, কিন্তু fly() override করছে
        throw logic_error("Ostrich can't fly!");
    }
};

void letBirdFly(Bird* bird) {
    bird->fly(); // 🛑 এখানে runtime exception আসবে Ostrich এর জন্য
}

int main() {
    Bird* bird1 = new Sparrow();
    letBirdFly(bird1); // ✅ OK

    Bird* bird2 = new Ostrich();
    letBirdFly(bird2); // ❌ Runtime Error: Ostrich can't fly!

    return 0;
}
// Note: This code violates the Liskov Substitution Principle (LSP) because Ostrich cannot fly,
// but it overrides the fly() method, leading to unexpected behavior when used in place of Bird.
// To fix this, we could redesign the class hierarchy to avoid such violations, for example by