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

int getMax(int teamSize[], int n) {
    int idx = -1;
    int maxi = 0;
    for(int i = 0; i < n; i ++) {
        if(teamSize[i] > maxi) {
            maxi = teamSize[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int teamCount, tableCount;
    int teamSize[128];
    int capacity;

    while(cin >> teamCount >> tableCount, teamCount || tableCount) {
        for(int i = 0; i < teamCount; i ++) {
            cin >> teamSize[i];
        }

        // sort(teamSize, teamSize + teamCount, greater<int>());

        priority_queue<pii> q;
        for(int i = 1; i <= tableCount; i ++) {
            cin >> capacity;
            q.push(pii(capacity, i));
        }

        vector<int> assignment[128];
        bool possible = true;
        for(int i = 0; i < teamCount; i ++) {

            int idx = getMax(teamSize,  teamCount);

            if(q.size() < teamSize[idx]) {
                possible = false;
                break;
            }

            vector<pii> thisTeam;
            for(int j = 0; j < teamSize[idx]; j ++) {
                pii pair = q.top();
                q.pop();
                pair.first --;
                assignment[idx].push_back(pair.second);
                if(pair.first > 0) {
                    thisTeam.push_back(pair);
                }
            }

            for(auto p : thisTeam) {
                q.push(p);
            }

            teamSize[idx] = -1;
        }

        if(possible) {
            cout << 1 << endl;
            for(int i = 0; i < teamCount; i ++) {
                for(int j = 0; j < assignment[i].size(); j ++) {
                    cout << (j == 0 ? "" : " ") << assignment[i][j];
                }
                cout << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }

	return 0;
}