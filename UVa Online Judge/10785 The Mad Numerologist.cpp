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

vector<pic> consonants;
vector<pic> vowels;

bool isvowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string lexicoFirst(string word) {
    string vow = "";
    string con = "";
    sort(word.begin(), word.end());

    for(char c : word) {
        if(isvowel(c)) {
            vow += c;
        } else {
            con += c;
        }
    }

    int i = 0;
    int j = 0;
    string result;
    for(int k = 0; k < word.size(); k ++) {
        result += (k % 2 == 0 ? vow[i ++] : con[j ++]);
    }
    return result;
}

string getWord(int n) {
    string word = "";
    int consonantsCount = 0;
    int cid = 0;
    int vowelsCount = 0;
    int vid = 0;

    for(int i = 0; i < n; i ++) {
        if(i % 2 == 1) {
            word += consonants[cid].second;
            consonantsCount ++;
            if(consonantsCount == 5) {
                cid ++;
                consonantsCount = 0;
            }
        } else {
            word += vowels[vid].second;
            vowelsCount ++;
            if(vowelsCount == 21) {
                vid ++;
                vowelsCount = 0;
            }
        }
    }

    return lexicoFirst(word);
}

void init() {
    int value = 1;
    char c = 'A';
    for(char c = 'A'; c <= 'Z'; c ++) {
        if(isvowel(c)) {
            vowels.push_back(pic(value, c));
        } else {
            consonants.push_back(pic(value, c));
        }

        value ++;
        if(value == 10) {
            value = 1;
        }
    }

    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int test;
    int n;
    cin >> test;
    for(int cas = 1; cas <= test; cas ++) {
        cin >> n;
        cout << "Case " << cas << ": " << getWord(n) << endl;
    }

	return 0;
}