#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // to ignore the newline after the number
    for (int i = 0; i < n; i++) {
        // Read a line of input
        string line;
        // Use getline to read the entire line including spaces
        // and ignore the newline character after the number
        getline(cin, line);
        stringstream ss(line); // create a string stream from the line
        string word, acronym = "";
        // Read each word from the string stream
        // and concatenate the first character of each word to form the acronym
        while (ss >> word) {
            acronym += word[0];
        }
        cout << acronym << endl;
    }
    return 0;
}
