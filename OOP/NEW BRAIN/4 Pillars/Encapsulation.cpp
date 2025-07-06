// Encapsulation: It describes the idea of bundling or wrapping of data (attributes) and methods (functions)  into a single unit called a class. 

/*
Advantages:
1. Encapsulation protects an object from unwanted access and modification.
*/
#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;  // 🔒 বাইরের দুনিয়া থেকে লুকানো

public:
    // Constructor
    BankAccount() {
        balance = 0;
    }

    // Setter - deposit function
    void deposit(int amount) {
        if (amount > 0)
            balance += amount;
    }

    // Getter - read-only access
    int getBalance() {
        return balance;
    }
};

int main() {
    BankAccount myAccount;

    myAccount.deposit(500);             // balance বাড়ানো গেলো
    cout << myAccount.getBalance();     // Output: 500

    // myAccount.balance = -999; ❌ এটা করা যাবে না, কারণ balance private
}
