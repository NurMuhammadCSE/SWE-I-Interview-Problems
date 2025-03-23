#include<bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    string name;
    string model;
    int price;

    void show(){
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

class BMW: public Vehicle{
public:
    string color;
    int year;

    void show(){
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    Vehicle v1; // v1 is an object of class Vehicle
    v1.name = "BMW";
    v1.model = "X5";
    v1.price = 100000;

    v1.show(); // calling the show() method of the object v1


    BMW b1; // b1 is an object of class BMW
    b1.name = "BMW";
    b1.model = "X5";
    b1.price = 100000;
    b1.color = "Black";
    b1.year = 2021;

    b1.show(); // calling the show() method of the object b1

    return 0;
}