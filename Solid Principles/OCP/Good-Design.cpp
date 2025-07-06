#include <iostream>
#include <string>
using namespace std;

// Abstract class (Interface)
class PaymentMethod {
public:
    virtual void pay() = 0; // Pure virtual function
};

// Concrete classes
class CreditCard : public PaymentMethod {
public:
    void pay() override {
        cout << "Paid using Credit Card" << endl;
    }
};

class Bkash : public PaymentMethod {
public:
    void pay() override {
        cout << "Paid using Bkash" << endl;
    }
};

class Nagad : public PaymentMethod {
public:
    void pay() override {
        cout << "Paid using Nagad" << endl;
    }
};

class PayPal : public PaymentMethod {
public:
    void pay() override {
        cout << "Paid using PayPal" << endl;
    }
};
class Rocket : public PaymentMethod {
public:
    void pay() override {
        cout << "Paid using Rocket" << endl;
    }
};

// High-level module (depends on abstraction, not concrete)
class PaymentProcessor {
public:
    void process(PaymentMethod* method) {
        method->pay(); // Runtime polymorphism
    }
};

int main() {
    PaymentProcessor processor;

    CreditCard creditCard;
    Bkash bkash;
    Nagad nagad;

    processor.process(&creditCard); // Output: Paid using Credit Card
    processor.process(&bkash);      // Output: Paid using Bkash
    processor.process(&nagad);      // Output: Paid using Nagad

    return 0;
}
