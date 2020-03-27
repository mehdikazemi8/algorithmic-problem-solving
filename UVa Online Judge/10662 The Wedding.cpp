#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 21;
const int INF = 1<<28;

int t, r, h;
int travelAgency[MAX_N];
int restaurant[MAX_N];
int hotel[MAX_N];

int travelAgency_restaurant[MAX_N][MAX_N];
int restaurant_hotel[MAX_N][MAX_N];
int hotel_travelAgency[MAX_N][MAX_N];

void readInput() {
	for(int i = 0; i < t; i ++) {
		cin >> travelAgency[i];
		for(int j = 0; j < r; j ++) {
			cin >> travelAgency_restaurant[i][j];
			travelAgency_restaurant[i][j] = 1 - travelAgency_restaurant[i][j];
		}
	}

	for(int i = 0; i < r; i ++) {
		cin >> restaurant[i];
		for(int j = 0; j < h; j ++) {
			cin >> restaurant_hotel[i][j];
			restaurant_hotel[i][j] = 1 - restaurant_hotel[i][j];
		}
	}

	for(int i = 0; i < h; i ++) {
		cin >> hotel[i];
		for(int j = 0; j < t; j ++) {
			cin >> hotel_travelAgency[i][j];
			hotel_travelAgency[i][j] = 1 - hotel_travelAgency[i][j];
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> t >> r >> h) {
    	readInput();

    	int tIndex = -1;
    	int rIndex = -1;
    	int hIndex = -1;
    	int best = INF;

    	for(int i = 0; i < t; i ++) {
    		for(int j = 0; j < r; j ++) {
    			for(int k = 0; k < h; k ++) {
    				if(travelAgency_restaurant[i][j] && 
    					restaurant_hotel[j][k] &&
    					hotel_travelAgency[k][i]) {

    					int sum = travelAgency[i] + restaurant[j] + hotel[k];
    					if(sum < best) {
    						best = sum;
    						tIndex = i;
    						rIndex = j;
    						hIndex = k;
    					}
    				}
    			}
    		}
    	}

    	if(best == INF) {
    		cout << "Don't get married!" << endl;
    	} else {
    		cout << tIndex << " " << rIndex << " " << hIndex << ":" << best << endl;
    	}
    }


	return 0;
}