#include <bits/stdc++.h>

using namespace std;

string solveFirstApproach(string variables, string binary, string unary) {
	if(variables.size() == 0) {
		return "no WFF possible";
	} else {
		string wff = "";
		wff += variables[0];
		variables.erase(variables.begin());

		while(variables.size() > 0 && binary.size() > 0) {
			wff = binary[0] + wff + variables[0];
			binary.erase(binary.begin());
			variables.erase(variables.begin());
		}

		wff = unary + wff;
		return wff;
	}
}

string solveSecondApproach(string variables, string binary, string unary) {
	if(variables.size() == 0) {
		return "no WFF possible";
	}
	
	int variablesCount = min(variables.size(), binary.size() + 1);
	int binaryCount = variablesCount - 1;
	return unary + binary.substr(0, binaryCount) + variables.substr(0, variablesCount); 
}

void chunk(string s, string &variables, string &binary, string &unary) {
	variables = binary = unary = "";
	for(char c : s) {
		if(islower(c)) {
			variables += c;
		} else if(c == 'N') {
			unary += c;
		} else {
			binary += c;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;

    while(cin >> s, s != "0") {
    	string binary;
    	string unary;
    	string variables;

    	chunk(s, variables, binary, unary);

    	cout << solveSecondApproach(variables, binary, unary) << endl;
    }

	return 0;
}