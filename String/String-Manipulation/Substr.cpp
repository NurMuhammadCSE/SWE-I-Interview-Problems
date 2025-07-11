#include <iostream>
using namespace std;

int main() {
    string s = "Bangladesh";

    string sub = s.substr(0, 5); // index 0 থেকে 5 ক্যারেক্টার
    cout << sub << endl; // Output: Bangl

    cout << s.substr(5, 4) << endl; // Output: ades
    cout << s.substr(7) << endl; // Output: ades

    return 0;
}
