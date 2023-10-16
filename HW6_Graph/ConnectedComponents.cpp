#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[node] = true;
    for (auto neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}

int connectedComponents(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n+1);
    for (auto edge : edges) {
        int x = edge.first;
        int y = edge.second;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n + 1, false);
    int cnt = 0;
    for (int node = 1; node <= n; node++) {
        if (!visited[node]) {
            dfs(node, visited, graph);
            cnt++;
        }
    }
    return cnt;
}

int main () {
    int n; cin >> n;
    int m; cin >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int y; cin >> y;
        edges.push_back({x, y});
    }
    cout << connectedComponents(n, edges);
}
