#include <bits/stdc++.h>

using namespace std;

#define pib pair<int,bool>

const int MAX_N = 128;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    int n, idx;
    int a[MAX_N];
    pib q[MAX_N * MAX_N];
    int freq[MAX_N];

    cin >> test;
    while(test --) {
    	cin >> n >> idx;
    	for(int i = 0; i < n; i ++) {
    		cin >> a[i];
    	}

    	memset(freq, 0, sizeof freq);
    	for(int i = 0; i < n; i ++) {
    		freq[a[i]] ++;
    	}

    	for(int i = 0; i < n; i ++) {
    		q[i] = pib(a[i], i == idx);
    	}

    	int i = 0;
    	int j = n;
    	int k = MAX_N - 1;
    	while(freq[k] == 0) {
    		k --;
    	}

    	int result = 0;
    	while(i < j) {
    		if(q[i].first == k) {
    			result ++;

    			if(q[i].second) {
    				break;
    			}

    			freq[k] --;
    			while(k >= 0 && freq[k] == 0) {
    				k --;
    			}
    			i ++;
    		} else {
    			q[j ++] = q[i ++];
    		}
    	}

    	cout << result << endl;
    }

	return 0;
}
