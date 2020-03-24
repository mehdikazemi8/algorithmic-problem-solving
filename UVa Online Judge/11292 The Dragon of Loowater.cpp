#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_N = 20010;

int knight[MAX_N];
int dragon[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;

    while(cin >> m >> n, m || n) {
    	for(int i = 0; i < m; i ++) {
    		cin >> dragon[i];
    	}

    	for(int i = 0; i < n; i ++) {
    		cin >> knight[i];
    	}

    	sort(dragon, dragon + m);
    	sort(knight, knight + n);
    	int i = 0; 
    	int j = 0;
    	ll total = 0;

    	while(i < m && j < n) {
    		if(dragon[i] <= knight[j]) {
    			total += knight[j];
    			i ++;
    			j ++;
    		} else {
    			j ++;
    		}
    	}

    	if(i == m) {
    		cout << total << endl;
    	} else {
    		cout << "Loowater is doomed!" << endl;
    	}

    }


	return 0;
}