#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 21;
const int INF = 1<<28;

int n = 3; // always 3 in this problem, [travel agency, restaurant, hotel]
int best;
int cost[MAX_N][MAX_N];
int mat[MAX_N][MAX_N][MAX_N][MAX_N];
int quantity[MAX_N];
int currentIndex[MAX_N];
int selectedIndex[MAX_N];

void readInput(int a, int b) {
    for(int i = 0; i < quantity[a]; i ++) {
        cin >> cost[a][i];

        for(int j = 0; j < quantity[b]; j ++) {
            cin >> mat[a][b][i][j];
            mat[a][b][i][j] = 1 - mat[a][b][i][j];
            mat[b][a][j][i] = mat[a][b][i][j];
        }
    }
}

void readInput() {
    memset(mat, 0, sizeof mat);
    readInput(0, 1);
    readInput(1, 2);
    readInput(2, 0);
}

void back(int a, int totalCost) {
    if(a == n) {
        if(totalCost < best) {
            best = totalCost;
            for(int i = 0; i < n; i ++) {
                selectedIndex[i] = currentIndex[i];
            }
        }
        return;
    }

    for(int i = 0; i < quantity[a]; i ++) {
        bool good = true;
        for(int b = 0; b < a; b ++) {
            int j = currentIndex[b];
            if(mat[a][b][i][j] == 0) {
                good = false;
                break;
            }
        }

        if(good) {
            currentIndex[a] = i;
            back(a+1, totalCost + cost[a][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> quantity[0] >> quantity[1] >> quantity[2]) {
    	readInput();

        best = INF;
        back(0, 0);

    	if(best == INF) {
    		cout << "Don't get married!" << endl;
    	} else {
    		cout << selectedIndex[0] << " " << selectedIndex[1] << " " << selectedIndex[2] << ":" << best << endl;
    	}
    }

	return 0;
}