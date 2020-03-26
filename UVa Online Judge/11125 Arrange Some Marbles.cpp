#include <bits/stdc++.h>

using namespace std;

int dp[8][8][8][8][4][5][4][6];

int f(vector<int> remain, int firstSize, int firstColor, int lastSize, int lastColor) {
	if(remain[1]+remain[2]+remain[3]+remain[4] == 0) {
		return firstSize != lastSize && firstColor != lastColor;
	}

	int &ref = dp[remain[1]][remain[2]][remain[3]][remain[4]][firstSize][firstColor][lastSize][lastColor];
	if(ref != -1) {
		return ref;
	}

	ref = 0;
	for(int color = 1; color <= 4; color ++) {
		if(color != lastColor) {
			for(int currentSize = 1; currentSize <= min(3, remain[color]); currentSize ++) {
				if(currentSize != lastSize) {
					remain[color] -= currentSize;
					ref += f(remain, 
						firstSize == 0 ? currentSize : firstSize,
						firstColor == 0 ? color : firstColor,
						currentSize,
						color
					);
					remain[color] += currentSize;
				}
			}	
		}
	}

	return ref;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof dp);

    int test;
    int n;

    cin >> test;
    while(test --) {
    	cin >> n;

    	int totalCount = 0;
    	int pile = 0;
    	vector<int> remain(5, 0);
    	for(int i = 1; i <= n; i ++) {
    		cin >> remain[i];
    		totalCount += remain[i];
    		if(remain[i] != 0) {
    			pile ++;
    		}
    	}

    	if(pile <= 1) {
    		if(totalCount <= 3) {
    			cout << 1 << endl;
    		} else {
    			cout << 0 << endl;
    		}
    	} else {
    		cout << f(remain, 0, 0, 5, 5) << endl;
    	}
    }

	return 0;
}