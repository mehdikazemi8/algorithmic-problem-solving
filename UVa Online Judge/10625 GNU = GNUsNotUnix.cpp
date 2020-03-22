#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull dp[128][10001];
bool computed[128][10001];
string rule[128];
char target;

void init() {
	for(int i = 0; i < 128; i ++) {
		rule[i] = "";
	}
}

ull f(char c, int step) {
	if(step == 0) {
		return target == c;
	}

	if(computed[c][step]) {
		return dp[c][step];
	}

	ull &ref = dp[c][step];
	ref = 0;
	for(char other : rule[c]) {
		if(rule[other].size() > 0) {
			ref += f(other, step-1);
		} else if(other == target) {
			ref ++;
		}
	}

	computed[c][step] = true;
	return ref;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    int n;
    int q;
    string temp;
    string start;
    int step;

    cin >> test;
    while(test --) {
    	init();

    	cin >> n;
    	for(int i = 0; i < n; i ++) {
    		cin >> temp;
    		rule[temp[0]] = temp.substr(3);
    	}
		
    	cin >> q;
    	while(q --) {
    		cin >> start >> target >> step;

    		for(int i = 0; i < 128; i ++) {
				for(int j = 0; j <= step; j ++) {
					computed[i][j] = false;
				}
			}

			ull result = 0;
			for(char c : start) {
				if(rule[c].size() > 0) {
					result += f(c, step);
				} else if(c == target) {
					result ++;
				}
			}
			cout << result << endl;
    	}
    }

	return 0;
}