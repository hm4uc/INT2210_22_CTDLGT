#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& graph, int dau, int cuoi) {
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), 0);
    queue<int> q;
    q.push(dau);
    visited[dau] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                if (neighbor == cuoi) {
                    return distance[neighbor];
                }
            }
        }
    }
    return -1;
}

int shortestPath(int n, vector<pair<int, int>>& edges, int X, int Y) {
    vector<vector<int>> graph(n + 1);
    for ( auto edge : edges) {
        int x = edge.first;
        int y = edge.second;
        graph[x].push_back(y);
    }
    return bfs(graph, X, Y);
}

int main () {
    int n; cin >> n;
    int m; cin >> m;
    int X; cin >> X;
    int Y; cin >> Y;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        int b; cin >> b;
        edges.push_back({a, b});
    }
    cout << shortestPath(n, edges, X, Y);
}
