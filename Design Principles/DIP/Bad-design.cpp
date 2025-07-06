#include <iostream>
using namespace std;

class MySQLDatabase {
public:
    void saveData(string data) {
        cout << "Saving '" << data << "' to MySQL database." << endl;
    }
};

class UserService {
    MySQLDatabase db;  // High-level module সরাসরি low-level module এ নির্ভরশীল
public:
    void addUser(string user) {
        db.saveData(user);
    }
};

int main() {
    UserService service;
    service.addUser("Nur Muhammad");
    return 0;
}
// Note: This code violates the Dependency Inversion Principle (DIP) because UserService is tightly coupled with MySQLDatabase.
// To adhere to DIP, we should introduce an abstraction (interface) for the database operations and make UserService depend on that abstraction instead of a concrete implementation.
