#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int INF = 1<<27;
const int MAX_N = 1000100;

vector<int> adj[MAX_N];
vector<long> color;
int wantedColor;

void createGraph(int n, vector<int> from, vector<int> to) {
    for(int i = 0; i < n; i ++) {
        adj[i].clear();
    }

    int x, y;
    for(int i = 0; i < from.size(); i ++) {
        x = from[i] - 1;
        y = to[i] - 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int shortestFromThis(int n, int source) {
    int dist[MAX_N];
    for(int i = 0; i < n; i ++) {
        dist[i] = -1;
    }

    queue<int> q;
    dist[source] = 0;
    q.push(source);
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();

        for(int other : adj[node]) {
            if(dist[other] == -1) {
                dist[other] = dist[node] + 1;
                q.push(other);
                if(color[other] == wantedColor) {
                    return dist[other];
                }
            }
        }
    }

    return INF;
}

int findShortest(int n, vector<int> from, vector<int> to, vector<long> _color, int _wantedColor) {
    color = _color;
    wantedColor = _wantedColor;

    if(count(color.begin(), color.end(), wantedColor) < 2) {
        return -1;
    }

    createGraph(n, from, to);

    int minDistance = INF;
    for(int i = 0; i < n; i ++) {
        if(color[i] == wantedColor) {
            minDistance = min(minDistance, shortestFromThis(n, i));
        }
    }
    return minDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
