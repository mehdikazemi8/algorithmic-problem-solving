#include <bits/stdc++.h>

using namespace std;

bool haveRepeatingDigits(int number) {
	bool mark[10];
	memset(mark, 0, sizeof mark);
	int digit;
	while(number) {
		digit = number % 10;
		if(mark[digit] == true) {
			return true;
		} else {
			mark[digit] = true;
			number /= 10;
		}
	}

	return false;
}

int differentDigits(int a, int b) {
	int result = 0;
	for(int x = a; x <= b; x ++) {
		if(!haveRepeatingDigits(x)) {
			result ++;
		}
	}
	return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;

    while(cin >> a >> b) {
    	cout << differentDigits(a, b) << endl;
    }

	return 0;
}