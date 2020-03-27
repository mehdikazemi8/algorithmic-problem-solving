#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int q;
    string x, y, line;
    map<string, string> dict;

    cin >> n;
    getline(cin, line);
    for(int i = 0; i < n; i ++) {
        getline(cin, x);
        getline(cin, y);
        dict[x] = y;
    }

    cin >> q;
    getline(cin, line);
    while(q --) {
        getline(cin, line);
        cout << dict[line] << endl;
    }

    return 0;
}