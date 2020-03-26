#include <bits/stdc++.h>

using namespace std;

void calculate(string line, int &a, int &b) {
	a = b = 0;
	bool firstDone = false;
	for(int i = 0; i < line.size(); i ++) {
		if(isdigit(line[i])) {
			if(firstDone) {
				b = line[i] - '0';
			} else {
				if(isdigit(line[i+1])) {
					a = (line[i] - '0') * 10 + line[i+1] - '0';
				} else {
					a = line[i] - '0';	
				}
				firstDone = true;
			}
			
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    int a, b;
    string line;

    cin >> test;
    getline(cin, line);
    for(int cas = 1; cas <= test; cas ++) {
    	getline(cin, line);

    	a = b = 0;
    	calculate(line, a, b);

    	cout << "Case " << cas << ": " << (a*500.0 + b*50) / 1000 << endl;
    }


	return 0;
}