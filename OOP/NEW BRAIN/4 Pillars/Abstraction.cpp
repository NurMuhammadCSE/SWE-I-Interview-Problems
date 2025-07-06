// Abstraction is providing only essential information about the data and hiding the unnecessary details or background implementation or details.
/*
Advantages: 
1. Simplifies complex systems by hiding unnecessary details.
2. Improves code readability and maintainability.

Abstraction means showing only the essential features of an object and hiding the internal implementation details from the user.
*/

#include <iostream>
using namespace std;

class Car {
public:
    void startEngine() {
        // ভিতরে অনেক কাজ হচ্ছে, কিন্তু ইউজার জানে না
        cout << "Engine started!" << endl;
    }

    void stopEngine() {
        cout << "Engine stopped!" << endl;
    }
};
class Bike {
public:
    void startEngine() {
        // ভিতরে অনেক কাজ হচ্ছে, কিন্তু ইউজার জানে না
        cout << "Bike engine started!" << endl;
    }

    void stopEngine() {
        cout << "Bike engine stopped!" << endl;
    }
};

int main() {
    Car myCar;
    myCar.startEngine();  // ইউজার শুধু এই ফাংশন কল করে কাজ করে
    myCar.stopEngine();

    Bike myBike;
    myBike.startEngine();
    myBike.stopEngine();

    return 0;
}