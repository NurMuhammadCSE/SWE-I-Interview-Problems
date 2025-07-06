#include <iostream>
using namespace std;

// Abstraction
class Database {
public:
    virtual void saveData(string data) = 0;
    virtual ~Database() = default;
};

// Low-level module
class MySQLDatabase : public Database {
public:
    void saveData(string data) override {
        cout << "Saving '" << data << "' to MySQL database." << endl;
    }
};

// High-level module
class UserService {
    Database& db;  // এখন abstraction এর ওপর নির্ভর
public:
    UserService(Database& database) : db(database) {}
    void addUser(string user) {
        db.saveData(user);
    }
};

int main() {
    MySQLDatabase mysql;
    UserService service(mysql);
    service.addUser("Nur Muhammad");
    return 0;
}
// Note: এই কোডে UserService এখন MySQLDatabase এর ওপর নির্ভরশীল নয়।
// বরং Database abstraction এর ওপর নির্ভরশীল।