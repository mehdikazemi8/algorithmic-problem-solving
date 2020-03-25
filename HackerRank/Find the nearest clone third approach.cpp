#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int MAX_N = 1000100;
vector<int> adj[MAX_N];

void createGraph(int n, vector<int> from, vector<int> to) {
    for(int i = 0; i < n; i ++) {
        adj[i].clear();
    }

    int x, y;
    for(int i = 0; i < from.size(); i ++) {
        x = from[i] - 1, y = to[i] - 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int calculateMinDistance(int n, int wantedColor, vector<long> &color) {
    int dist[MAX_N];
    int parent[MAX_N];
    for(int i = 0; i < n; i ++) {
        dist[i] = -1;
        parent[i] = -1;
    }

    queue<int> q;
    for(int node = 0; node < n; node++) {
        if(color[node] == wantedColor) {
            dist[node] = 0;
            q.push(node);
        }
    }

    int node;
    while(!q.empty()) {
        node = q.front();
        q.pop();

        for(int other : adj[node]) {
            if(dist[other] == -1) {
                parent[other] = node;
                dist[other] = dist[node] + 1;
                q.push(other);
            } else if(other != parent[node]) {
                return dist[node] + dist[other] + 1;
            }
        }
    }

    return -1;
}

int findShortest(int n, vector<int> from, vector<int> to, vector<long> color, int wantedColor) {
    if(count(color.begin(), color.end(), wantedColor) < 2) {
        return -1;
    }

    createGraph(n, from, to);

    return calculateMinDistance(n, wantedColor, color);
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
