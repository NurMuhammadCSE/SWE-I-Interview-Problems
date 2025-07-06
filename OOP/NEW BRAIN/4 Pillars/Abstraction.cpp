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