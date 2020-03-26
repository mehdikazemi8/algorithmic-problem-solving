#include <bits/stdc++.h>

using namespace std;

#define ll long long

void fillDate(string date, string &month, int &day, ll &year) {
	stringstream ssin(date);
	char comma;
	ssin >> month >> day >> comma >> year;
}

ll getStart(string start) {
	string month;
	int day;
	ll year;
	fillDate(start, month, day, year);

	if(month == "January" || month == "February") {
		return year;
	} else {
		return year+1;
	}
}

ll getEnd(string end) {
	string month;
	int day;
	ll year;
	fillDate(end, month, day, year);

	if(month == "January" || (month == "February" && day <= 28)) {
		return year-1;
	} else {
		return year;
	}
}

ll countLeap(ll n) {
	return n / 4 - n / 100 + n / 400;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    string start, end;
    string temp;

    cin >> test;
    getline(cin, temp);
    for(int cas = 1; cas <= test; cas ++) {
    	getline(cin, start);
    	getline(cin, end);

    	ll a = getStart(start);
    	ll b = getEnd(end);

    	cout << "Case " << cas << ": " << countLeap(b) - countLeap(a-1) << endl;
    }

	return 0;
}