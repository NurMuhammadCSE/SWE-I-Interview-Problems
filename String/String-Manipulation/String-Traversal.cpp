#include <iostream>
using namespace std;

int main() {
    string name = "nur";

    for (int i = 0; i < name.size(); i++) {
        cout << name[i] << " ";
    }
    cout << endl;

    for (char ch : name) {
        cout << ch << " ";
    }
    cout << endl;

    int i = 0;
    while (i < name.length()) {
        cout << name[i] << " ";
        i++;
    }
    cout << endl;

    string s = "hello";
    int count = 0;

    for (char ch : s) {
        count++;
    }

    cout << "Total characters: " << count << endl;
    cout << "Total characters: " << s.length() << endl;

    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }

    int left = 0, right = s.length() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    cout << "\nReversed string: " << s << endl;

    string vowelCheck = "MUhammad";
    int cnt = 0;
    // for (int i = 0; i < vowelCheck.size(); i++)
    // {
    //     if (vowelCheck[i] == 'a' || vowelCheck[i] == 'e' || vowelCheck[i] == 'i' || vowelCheck[i] == 'o' || vowelCheck[i] == 'u')
    //     {
    //         cnt++;
    //     }
    // }
    // cout << cnt << endl;

    for (int i = 0; i < vowelCheck.size(); i++) {
        char ch = tolower(vowelCheck[i]); // বড় অক্ষর থাকলে ছোট বানিয়ে নিচ্ছি

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            cnt++;
        }
    }

    cout << cnt << endl;
    

    return 0;
}
