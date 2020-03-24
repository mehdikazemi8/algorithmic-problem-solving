#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

const int MAX_N = 1000010;
const int INF = 1<<28;

vector<int> adj[MAX_N];
vector<long> color;
int minDistance;
int wantedColor;

void createGraph(int n, vector<int> &from, vector<int> &to) {
    for(int i = 0; i < n; i ++) {
        adj[i].clear();
    }

    for(int i = 0; i < from.size(); i ++) {
        from[i] --;
        to[i] --;
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
}

int dfs(int node, int parent) {
    int minFromThisNode = color[node] == wantedColor ? 0 : INF;
    vector<int> dists;
    for(int other : adj[node]) {
        if(other != parent) {
            dists.push_back(dfs(other, node));
        }
    }

    if(dists.size() == 0) {
         return minFromThisNode;
    }

    sort(dists.begin(), dists.end());
    minFromThisNode = min(minFromThisNode, dists[0] + 1);
    if(color[node] == wantedColor) {
        minDistance = min(minDistance, dists[0] + 1);
    }

    if(dists.size() >= 2) {
        minDistance = min(minDistance, dists[0] + dists[1] + 2);
    }

    return minFromThisNode;
}

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int findShortest(int nodeCount, vector<int> from, vector<int> to, vector<long> _color, int _wantedColor) {
    color = _color;
    wantedColor = _wantedColor;

    createGraph(nodeCount, from, to);

    if(count(color.begin(), color.end(), wantedColor) < 2) {
        return -1;
    }
    
    minDistance = INF;
    dfs(0, -1);
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
