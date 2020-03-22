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

const int MAX_N = 1000100;

int startIndex, endIndex;
string source;
string q;
int nextIndex[MAX_N][52];

inline int intValue(char c) {
    if(islower(c)) return c-'a';
    return c-'A'+26;
}

void solve(int i, int j) {
    if(j == q.size()) {
        endIndex = i-1;
        return;
    }
    if(i == source.size()) {
        return;
    }

    int idx = nextIndex[i][intValue(q[j])];
    if(idx == -1) {
        return;
    }

    if(startIndex == -1) {
        startIndex = idx;
    }

    solve(idx+1, j+1);
}

void init() {
    for(int i = 0; i < MAX_N; i ++) {
        for(int j = 0; j < 52; j ++) {
            nextIndex[i][j] = -1;
        }
    }

    for(int i = source.size()-1; i >= 0; i --) {
        for(int j = 0; j < 52; j ++) {
            nextIndex[i][j] = nextIndex[i+1][j];
        }

        nextIndex[i][intValue(source[i])] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int queryCount;

    cin >> source;

    init();

    cin >> queryCount;
    while(queryCount --) {
        cin >> q;
        startIndex = endIndex = -1;
        solve(0, 0);
        if(endIndex == -1) {
            cout << "Not matched" << endl;
        } else {
            cout << "Matched " << startIndex << " " << endIndex << endl; 
        }
    }

	return 0;
}