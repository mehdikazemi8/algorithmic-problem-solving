#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    while(cin >> a >> b) {
    	if(a == b) {
    		cout << a << endl;
    	} else {
    		cout << max(a, b) << endl;
    	}
    }

	return 0;
}