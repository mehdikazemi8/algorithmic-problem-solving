#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int MAX_N = 100100;
int freq[MAX_N][10];
int v[MAX_N];

int main() {
	int n, d;
	string s;

	while(cin >> n >> d, n || d) {
		for(int i = 0; i <= n; i ++) {
			for(int d = 0; d < 10; d ++) {
				freq[i][d] = 0;
			}
		}
		int remain = n-d;

		cin >> s;
		for(int i = 0; i < n; i ++) {
			for(int d = 0; d < 10; d ++) {
				freq[i+1][d] = freq[i][d];
			}
			v[i+1] = s[i] - '0';
			freq[i+1][v[i+1]] ++;
		}

		string output = "";
		int i = 1;
		int j = n-remain+1;

		while(output.size() < remain) {
			int maxDigit = -1;
			for(int digit = 9; digit >= 0; digit --) {
				if(freq[j][digit] - freq[i-1][digit] > 0) {
					maxDigit = digit;
					break;
				}
			}

			output += char('0' + maxDigit);

			while(true) {
				if(v[i] == maxDigit) {
					break;
				} else {
					i ++;
				}
			}
			i ++;
			j ++;	
		}

		cout << output << endl;
 	}

	return 0;
}
