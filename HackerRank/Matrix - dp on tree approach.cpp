#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#define pii pair<int,int>

const int MAX_N = 100100;
const int INF = 1<<30;

bool hasMachine[MAX_N];
vector<pii> adj[MAX_N];
int dp[MAX_N][2];

int calc(int node, int machineCount, int parent) {
    if(machineCount == 0 && hasMachine[node] == true) {
        return INF;
    }

    int &ref = dp[node][machineCount];
    if(ref != -1) {
        return ref;
    }

    int zeroSum = 0;
    int child, cost;
    for(auto pair : adj[node]) {
        child = pair.first, cost = pair.second;
        if(child != parent) {
            zeroSum += min( calc(child, 0, node), calc(child, 1, node) + cost );
        }
    }

    if( (machineCount == 0 && hasMachine[node] == false) ||
        (machineCount == 1 && hasMachine[node] == true)) {
        return ref = zeroSum;
    }

    // machineCount = 1, hasMachine[node] = false
    int temp;
    int result = INF;
    for(auto pair : adj[node]) {
        child = pair.first, cost = pair.second;
        if(child != parent) {
            temp = min( calc(child, 0, node), calc(child, 1, node) + cost );
            result = min(result, zeroSum - temp + calc(child, 1, node));
        }
    }

    return ref = result;
}

void init(int n) {
    for(int i = 0; i < n; i ++) {
        adj[i].clear();
        hasMachine[i] = false;
    }
}

int main()
{
    int n, k;
    int x, y, cost, machine;

    cin >> n >> k;

    init(n);

    for(int i = 1; i < n; i ++) {
        cin >> x >> y >> cost;
        adj[x].push_back(pii(y, cost));
        adj[y].push_back(pii(x, cost));
    }

    for(int i = 0; i < k; i ++) {
        cin >> machine;
        hasMachine[machine] = true;
    }

    memset(dp, -1, sizeof dp);
    cout << min( calc(0, 0, -1), calc(0, 1, -1) ) << endl;

    return 0;
}
