#include<bits/stdc++.h>
using namespace std;

bool isArmstrong(int num) {
    int original = num;
	int digits = 0;
	int armstrong = 0;

	while(num){
		num /= 10;
		digits++;
	}
	num = original;
	while(num){
		int ld = num % 10;
		armstrong += pow(ld, digits);
		num /= 10;
	}
	return original == armstrong;
}

int main() {
    int n;
    cin >> n;
    cout << isArmstrong(n);
    return 0;
}