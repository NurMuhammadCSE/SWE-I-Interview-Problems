#include <iostream>
#include <string>
using namespace std;

class Payment {
public:
    void processPayment(string method) {
        if (method == "CreditCard") {
            cout << "Processing Credit Card Payment" << endl;
        } else if (method == "Bkash") {
            cout << "Processing Bkash Payment" << endl;
        } else if (method == "Nagad") {
            cout << "Processing Nagad Payment" << endl;
        }
        // এরপর যদি PayPal বা Rocket যোগ করতে চাও,
        // তাহলে আবার এই class এ modify করতে হবে
    }
};

int main() {
    Payment payment;
    payment.processPayment("Bkash");
    payment.processPayment("CreditCard");
    payment.processPayment("Nagad");

    return 0;
}
