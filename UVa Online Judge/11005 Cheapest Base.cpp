#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define pic pair<int,char>

string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cost[64];
const int INF = 1<<28;

int calculateCost(ll n, int base) {
    if(n == 0) {
        return cost[0];
    }

    int result = 0;
    int digit;
    while(n > 0) {
        digit = n % base;
        n /= base;
        result += cost[digit];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int test;
    ll n;
    int query;

    cin >> test;
    for(int cas = 1; cas <= test; cas ++) {
        for(int i = 0; i < alpha.size(); i ++) {
            cin >> cost[i];
        }

        cout << "Case " << cas << ":" << endl;

        cin >> query;
        while(query --) {
            cin >> n;
            vector<int> allCosts;
            for(int base = 2; base <= 36; base ++) {
                allCosts.push_back(calculateCost(n, base));
            }

            int mini = INF;
            for(int c : allCosts) {
                mini = min(c, mini);
            }

            cout << "Cheapest base(s) for number " << n << ":";
            for(int i = 0; i < allCosts.size(); i ++) {
                if(allCosts[i] == mini) {
                    cout << " " << i+2;
                }
            }
            cout << endl;
        }

        if(cas != test) {
            cout << endl;
        }
    }

	return 0;
}