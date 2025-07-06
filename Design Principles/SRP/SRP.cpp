#include <iostream>
#include <string>
using namespace std;

// Class for baking bread
class BreadBaker {
public:
    void bakeBread() {
        cout << "Baking high-quality bread..." << endl;
    }
};

// Class for managing inventory
class InventoryManager {
public:
    void manageInventory() {
        cout << "Managing inventory..." << endl;
    }
};

// Class for ordering supplies
class SupplyOrder {
public:
    void orderSupplies() {
        cout << "Ordering supplies..." << endl;
    }
};

// Class for serving customers
class CustomerService {
public:
    void serveCustomer() {
        cout << "Serving customers..." << endl;
    }
};

// Class for cleaning the bakery
class BakeryCleaner {
public:
    void cleanBakery() {
        cout << "Cleaning the bakery..." << endl;
    }
};

int main() {
    BreadBaker baker;
    InventoryManager inventoryManager;
    SupplyOrder supplyOrder;
    CustomerService customerService;
    BakeryCleaner cleaner;

    // Each class focuses on its specific responsibility
    baker.bakeBread();
    inventoryManager.manageInventory();
    supplyOrder.orderSupplies();
    customerService.serveCustomer();
    cleaner.cleanBakery();

    return 0;
}