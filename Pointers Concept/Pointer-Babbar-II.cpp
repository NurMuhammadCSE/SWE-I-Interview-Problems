#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4}; // প্রথম চারটি ইনডেক্স দেওয়া আছে, বাকিগুলো ডিফল্ট 0 হবে।

    cout << "arr[0]: " << arr[0] << ", Address: " << &arr[0] << endl;
    cout << "arr[2]: " << arr[2] << ", Address: " << &arr[2] << endl;

    // Pointer ব্যবহার করে Access করা
    int *p = arr; // arr-এর প্রথম ইলিমেন্টকে পয়েন্ট করছে

    cout << "Dereferencing arr: " << *arr << endl;                                 // arr[0] এর মান দেখাবে
    cout << "Dereferencing with Addition (*arr + 1): " << *arr + 1 << endl;        // arr[0] + 1 (1 + 1 = 2)
    cout << "Pointer Arithmetic (*(arr + 1)): " << *(arr + 1) << endl;             // arr[1] এর মান দেখাবে (2)
    cout << "Adding 1 to Dereferenced Value (*(arr) + 1): " << *(arr) + 1 << endl; // arr[0] + 1 দেখাবে (1+1=2)
    cout << "arr[2] (Direct Access): " << arr[2] << endl;
    cout << "arr[2] (Pointer Access *(arr+2)): " << *(arr + 2) << endl;

    // Extra: Address checking
    cout << "\nPointer Variable p holds: " << p << endl;
    cout << "Address of p: " << &p << endl;
    cout << "Value at p (Dereferencing *p): " << *p << endl;

    float f = 10.5;
    float newP = 2.5; // Renamed variable to avoid conflict
    float *ptr = &f;
    (*ptr)++;
    *ptr = newP;
    cout << *ptr << " " << f << " " << newP;
    return 0;
}
