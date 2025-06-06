#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}


bool isPrime(int num) {
    if(num <= 1) return false;
    for(int i=2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;  

    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) {  
            cout << i << endl;  
        }
    }

    return 0;
}
