#include<bits/stdc++.h>
using namespace std;

int main() {
    // Declare and initialize a string

    // char ch = 'a';
    // cout << ch << endl;

    // // string name = "Nur Muhammad";
    // // cout << name << endl;

    // string name;
    // // cin >> name;
    // // cout << name << endl;

    // getline(cin, name);
    // cout << name << endl;


    // Accessing Characters
    // string greet = "Hello";
    // cout << greet[0] << endl;
    // cout << greet[1] << endl;
    // cout << greet[5] << endl;

    // greet[0] = 'A';
    // cout << greet[0] << endl;
    // cout << greet << endl;


    // string country = "Bangladesh";
    // cout << country.length() << endl;
    // cout << country.size() << endl;

    // for (int i = 0; i < country.size(); i++)
    // {
    //     cout << country[i] << " ";
    // }
    // cout << endl;

    // string fName = "Nur";
    // string lName = "Muhammad";

    // string fullName = fName + " " + lName;
    // cout << fullName << endl;

    // fName.append(lName);

    // cout << fName << endl;
    
    // string name;
    // getline(cin, name);

    // cout << name << endl;
    
    // // if (!name.empty()) {}
    // name[0] = toupper(name[0]); // Capitalize the first letter

    // cout << name << endl;
    // string str = name;

    // for (int i = 0; i < str.size(); i++)
    // {
    //     if(i == 0 || str[i-1] == ' '){
    //         str[i] = toupper(str[i]);
    //     }else{
    //         str[i] = tolower(str[i]);
    //     }
    // }
    
    // cout << str << endl;


    // Capitalize the All letters of word in a string
    // string name;
    // getline(cin, name);

    // for (int i = 0; i < name.size(); i++) {
    //     name[i] = toupper(name[i]);
    // }

    // cout << name << endl;


    // 
    string name;
    getline(cin, name);

    for (int i = 0; i < name.size(); i++) {
        name[i] = tolower(name[i]);
    }

    cout << name << endl;


    return 0;
}