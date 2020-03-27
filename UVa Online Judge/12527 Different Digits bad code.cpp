#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;

    while(cin >> a >> b) {
    	int result = 0;
    	for(int x = a; x <= b; x ++) {
    		bool mark[10];
    		memset(mark, 0, sizeof mark);
    		int number = x;
    		int digit;
    		bool haveRepating = false;
    		while(number) {
    			digit = number % 10;
    			if(mark[digit] == true) {
    				haveRepating = true;
    				break;
    			} else {
    				number /= 10;
    				mark[digit] = true;
    			}
    		}

    		if(haveRepating == false) {
    			result ++;
    		}
    	}

    	cout << result << endl;
    }

    

	return 0;
}
