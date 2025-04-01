#include<bits/stdc++.h>
using namespace std;

int main() {
    int a = 10;
    int *p = &a; // Pointer p stores the address of variable a

    cout << "Value of a: " << a << endl; // Output: 10
    cout << "Address of a: " << &a << endl; // Output: Address of a
    cout << "Value at pointer p: " << *p << endl; // Output: 10
    cout << "Address stored in pointer p: " << p << endl; // Output: Address of a

    return 0;
}