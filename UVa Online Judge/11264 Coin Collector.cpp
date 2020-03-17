#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    int n;
    ll x[1024];
    ll sum[1024];

    cin >> test;

    while(test --) {
        cin >> n;
        for(int i = 0; i < n; i ++) {
            cin >> x[i];
        }

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        int result = 2;
        ll currentSum = 1;
        for(int i = 1; i < n-1; i ++) {
            if(currentSum+x[i] < x[i+1]) {
                result ++;
                currentSum += x[i];
            }
        }

        cout << result << endl;
    }

	return 0;
}