#include<bits/stdc++.h>
using namespace std;

int main(){
    // int num = 10;
    // cout << num << endl;
    // // Address of Operator -> &
    // cout << &num << endl; // Address

    // int *ptr = &num; // Pointer stored Memory Address
    // cout << ptr << endl; // Address
    // cout << *ptr << endl; // Value

    // int i = 5;
    // cout << sizeof(i) << " " << i << endl;
    // cout << sizeof(&i) << " " << &i << endl;

    // int *pt = &i;
    // cout << sizeof(*pt) << " " << *pt << endl;
    // cout << sizeof(pt) << " " << pt << endl;

    // int number = 10;
    // int num2 = number;
    // number++;
    // num2++;
    // cout << number << endl;
    // cout << num2 << endl;

    // int *pt2 = &number;
    // (*pt2)++;
    // cout << (*pt2)++ << endl;
    // cout << *pt2 << endl;
    // cout << pt2 << endl;

    // int i = 5;
    // int *p = &i;

    // cout << p << endl; // Address 
    // cout << *p << endl; // Value

    // int *p2 = 0;
    // p2 = &i;

    // cout << p2 << endl;
    // cout << *p2 << endl;


    // int num = 5;
    // int a = num;
    // a++;

    // cout << num << endl;
    // cout << a << endl;

    // int *pt = &num;

    // cout << pt << endl;
    // cout << *pt << endl;
    // cout << num << endl;
    // (*pt)++;
    // cout << pt << " " << num << endl;
    // cout << *pt << " " << num << endl;
    
    // cout << num << endl;

    // int i = 5;
    // int *ptr = &i;

    // cout << ptr << endl;
    // cout << *ptr << endl;

    // int *ptr2 = ptr;
    // cout << ptr2 << " " << ptr << endl;
    // cout << *ptr2 << " " << ptr << endl;

    // Important Concept
    int i = 5;
    int *p = &i;

    *p = *p + 1;
    cout << *p << endl;

    cout << "Before " << p << endl;
    p = p + 1;
    cout << "After " << p << endl;

}

// Coding Ninjas => CodeStudio -> Guided Paths -> Pointers