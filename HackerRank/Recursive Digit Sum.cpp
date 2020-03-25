#include <bits/stdc++.h>

using namespace std;

#define ll long long

int calc(ll number) {
    if(number <= 9) {
        return number;
    }

    ll digitsSum = 0;
    while(number > 0) {
        digitsSum += number % 10;
        number /= 10;
    }
    return calc(digitsSum);
}

int superDigit(string n, int k) {
    ll digitsSum = 0;
    for(char c : n) {
        digitsSum += c-'0';
    }

    return calc(digitsSum * k);
}

int main()
{
    string n;
    int k;
    cin >> n >> k;

    cout << superDigit(n, k) << endl;

    return 0;
}
