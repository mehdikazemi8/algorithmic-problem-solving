#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 128;
const int MAX_EDGE = 1024;
const int INF = 1<<29;

struct Edge {
	int x, y, cost;
	Edge(int _x = 0, int _y = 0, int _cost = 0) {
		x = _x;
		y = _y;
		cost = _cost;
	}
};

class Graph {
public:
	map<string, int> cityIndex;
	string city[MAX_NODE];
	Edge edge[MAX_EDGE];
	bool isLastTest;
	int testNumber;
	int n, m;

	Graph(int _testNumber, bool _isLastTest) {
		this->isLastTest = _isLastTest;
		this->testNumber = _testNumber;
	}

	int getIndex(string cityName) {
		if(cityIndex.find(cityName) != cityIndex.end()) {
			return cityIndex[cityName];
		}

		int currentIndex = cityIndex.size();
		cityIndex[cityName] = currentIndex;
		return currentIndex;
	}

	void inputGraph() {
		cin >> n;
		for(int i = 0; i < n; i ++) {
			cin >> city[i];
			getIndex(city[i]);
		}

		string first, second;
		int cost;
		int firstIndex, secondIndex;

		cin >> m;
		for(int i = 0; i < m; i ++) {
			cin >> first >> second >> cost;
			firstIndex = getIndex(first);
			secondIndex = getIndex(second);
			edge[i] = Edge(firstIndex, secondIndex, cost);
		}
	}

	int calculateMinDistance(int stopCount) {
		int dist[MAX_NODE];
		for(int i = 0; i < n; i ++) {
			dist[i] = INF;
		}
		dist[0] = 0;

		for(int i = 0; i <= stopCount; i ++) {
			int temp[MAX_NODE];
			for(int i = 0; i < n; i ++) {
				temp[i] = dist[i];
			}

			for(int j = 0; j < m; j ++) {
				temp[edge[j].y] = min(temp[edge[j].y], dist[edge[j].x] + edge[j].cost);
			}

			for(int i = 0; i < n; i ++) {
				dist[i] = temp[i];
			}
		}

		return dist[n-1];
	}

	void solve() {
		inputGraph();

		cout << "Scenario #" << testNumber << endl;

		int q;
		int stopCount;
		cin >> q;
		while(q --) {
			cin >> stopCount;
			int minDistance = calculateMinDistance(stopCount);

			if(minDistance != INF) {
				cout << "Total cost of flight(s) is $" << minDistance << endl;	
			} else {
				cout << "No satisfactory flights" << endl;
			}
			
		}

		if(!isLastTest) {
			cout << endl;
		}
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    for(int cas = 1; cas <= test; cas ++) {
    	Graph g = Graph(cas, cas==test);
    	g.solve();
    }

	return 0;
}