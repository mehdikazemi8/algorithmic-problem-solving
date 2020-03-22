#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int INF = 1<<28;
const int SHIFT = 50;

bool dp[103][53][5003];
int x[103];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int totalSum;
    while(cin >> n >> m) {
    	totalSum = 0;
    	for(int i = 1; i <= n+m; i ++) {
    		cin >> x[i];
    		x[i] += SHIFT;
    		totalSum += x[i];
    	}

    	if(n > m) {
    		swap(n, m);
    	}

    	for(int i = 0; i <= n+m; i ++) {
    		for(int j = 0; j <= n; j ++) {
    			for(int sum = 0; sum <= totalSum; sum ++) {
    				dp[i][j][sum] = false;
    			}
    		}
    	}

    	dp[0][0][0] = true;
    	for(int i = 0; i <= n+m; i ++) {
    		for(int j = 0; j <= n; j ++) {
    			for(int sum = 0; sum <= totalSum; sum ++) {
    				if(dp[i][j][sum]) {
    					dp[i+1][j][sum] = true;
    					dp[i+1][j+1][sum+x[i+1]] = true;
    				}
    			}
    		}
    	}

    	int mini = INF;
    	int maxi = -INF;
    	int first, second;
    	for(int sum = 0; sum <= totalSum; sum ++) {
    		if(dp[n+m][n][sum]) {
    			first = sum; 
    			second = totalSum - sum;
    			first -= n * SHIFT;
    			second -= m * SHIFT;

    			mini = min(mini, first*second);
    			maxi = max(maxi, first*second);
    		}
    	}

    	cout << maxi << " " << mini << endl; 
    }


	return 0;
}