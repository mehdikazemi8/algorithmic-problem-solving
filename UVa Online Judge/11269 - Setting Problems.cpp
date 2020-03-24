#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

int f(pii x, pii y) {
	if(x.second >= y.first) {
		return x.first + x.second + y.second;
	} else {
		return x.first + y.first + y.second;
	}
}

bool comp(pii x, pii y) {
	return f(x, y) <= f(y, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    pii a[128];

    while(cin >> n) {
    	for(int i = 0; i < n; i ++) {
    		cin >> a[i].first;
    	}

    	for(int i = 0; i < n; i ++) {
    		cin >> a[i].second;
    	}

    	sort(a, a+n, comp);

    	int firstSum = 0;
    	int secondSum = 0;
    	for(int i = 0; i < n; i ++) {
    		firstSum += a[i].first;
    		if(secondSum >= firstSum) {
    			secondSum = secondSum + a[i].second;
    		} else {
    			secondSum = firstSum + a[i].second;
    		}
    	}

    	cout << secondSum << endl;
    }


	return 0;
}