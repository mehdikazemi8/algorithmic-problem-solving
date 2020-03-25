#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct Edge {
    int x, y, cost;
    Edge(int _x, int _y, int _cost) {
        x = _x;
        y = _y;
        cost = _cost;
    }

    const bool operator<(const Edge & other) const {
        return cost > other.cost;
    }

    void print() {
        cout << x << " " << y << " -> " << cost << endl;
    }
};

const int MAX_N = 100100;
int parent[MAX_N];
bool hasMachine[MAX_N];

int find(int x) {
    if(x == parent[x]) {
        return x;
    }

    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int parx = find(x);
    int pary = find(y);

    parent[parx] = pary;
    hasMachine[pary] |= hasMachine[parx];
}

// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
    vector<Edge> all;
    for(auto r : roads) {
        all.push_back(Edge(r[0], r[1], r[2]));
    }

    for(int i = 0; i < MAX_N; i ++) {
        parent[i] = i;
        hasMachine[i] = false;
    }

    for(int node : machines) {
        hasMachine[node] = true;
    }

    int result = 0;
    sort(all.begin(), all.end());
    for(auto e : all) {
        if(find(e.x) == find(e.y)) {
            continue;
        }

        if(hasMachine[find(e.x)] && hasMachine[find(e.y)]) {
            result += e.cost;
            continue;
        }

        merge(e.x, e.y);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    // ofstream fout("mine.txt");

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

    fout << result << "\n";

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
