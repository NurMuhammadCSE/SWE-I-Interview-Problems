/*
অবজেক্ট হলো ক্লাসের বাস্তব রূপ (Instance)।
তুমি যখন ক্লাস নামের নকশা দিয়ে কিছু "বস্তুর মতো জিনিস" বানাও — তখন সেটাই অবজেক্ট।

🏠 বাস্তব উদাহরণ:
ধরো, "ঘর" (House) বানানোর জন্য তোমার কাছে একটা নকশা (Design) আছে।
ওই নকশাটা হচ্ছে Class
আর তুমি সেই নকশা অনুযায়ী বানানো ঘরগুলো যেগুলো বাসযোগ্য – সেগুলো হচ্ছে Object
*/

// An object is any real-world entity that has some characteristics (properties) and behaviors (actions). It is also called an instance of a class.

#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string brand;
    int year;

    void start() {
        cout << brand << " is starting..." << endl;
    }
};

int main() {
    Car car1; // এটা হলো অবজেক্ট: car1
    car1.brand = "Toyota";
    car1.year = 2023;
    car1.start(); // Output: Toyota is starting...
    
    Car car2; // আরেকটা অবজেক্ট
    car2.brand = "BMW";
    car2.year = 2025;
    car2.start(); // Output: BMW is starting...
}

/*
📦 একটি অবজেক্ট কী ধারণ করে?
Properties: আলাদা আলাদা ভ্যালু থাকে (brand = "Toyota")
Functions ব্যবহার করতে পারে: start(), drive(), etc.
প্রতিটি অবজেক্টের ডেটা আলাদা হয়, কিন্তু ফাংশন/মেথড এক থাকে — কারণ এগুলো ক্লাস থেকে পাওয়া।

"অবজেক্ট = ক্লাসের একটা করে চিরায়ত রূপ"
*/