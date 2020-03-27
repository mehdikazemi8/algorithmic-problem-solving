#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 26;

class Graph {
public:
	int nodeCount;
	string initialWakeUp;
	int mat[MAX_N][MAX_N];

	Graph(int nodeCount, string initialWakeUp, vector<string> edges) {
		this->nodeCount = nodeCount;
		this->initialWakeUp = initialWakeUp;

		createGraph(edges);
	}

	void createGraph(vector<string> edges) {
		memset(mat, 0, sizeof mat);
		int x, y;
		for(auto e : edges) {
			x = e[0] - 'A';
			y = e[1] - 'A';

			mat[x][y] = mat[y][x] = 1;
		}
	}

	string solve() {
		int maxDistance = 0;
		int visitedCount = 0;
		queue<int> q;
		int dist[MAX_N];
		int wokeUpCount[MAX_N];
		memset(wokeUpCount, 0, sizeof wokeUpCount);
		memset(dist, -1, sizeof dist);

		for(char c : initialWakeUp) {
			int node = c-'A';
			dist[node] = 0;
			wokeUpCount[node] = 3;
			q.push(node);
		}

		while(!q.empty()) {
			int node = q.front();
			q.pop();
			visitedCount ++;

			for(int other = 0; other < MAX_N; other ++) {
				if(mat[node][other] == 1 && dist[other] == -1) {
					wokeUpCount[other] ++;
					if(wokeUpCount[other] == 3) {
						dist[other] = dist[node] + 1;
						q.push(other);
					}
				}
			}

			maxDistance = dist[node];
		}

		if(visitedCount == nodeCount) {
			return "WAKE UP IN, " + toStr(maxDistance) + ", YEARS";
		} else {
			return "THIS BRAIN NEVER WAKES UP";
		}
	}

	string toStr(int number) {
		ostringstream oss;
		oss << number;
		return oss.str();
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string initialWakeUp;
    vector<string> edges;
    while(cin >> n >> m >> initialWakeUp) {
    	edges.resize(m);
    	for(int i = 0; i < m; i ++) {
    		cin >> edges[i];
    	}

    	cout << Graph(n, initialWakeUp, edges).solve() << endl;
    }

	return 0;
}