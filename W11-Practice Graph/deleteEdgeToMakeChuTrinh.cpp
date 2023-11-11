#include <iostream>
#include <vector>

using namespace std;

const int maxx = 1000;
int parent[maxx];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    parent[v] = u;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int lastEdge = -1;
    for (int i = 0; i < n; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        int uRoot = find(u);
        int vRoot = find(v);

        if (uRoot != vRoot) {
            parent[vRoot] = uRoot;
        } else {
            lastEdge = i;
        }
    }

    cout << edges[lastEdge].first << " " << edges[lastEdge].second << endl;

    return 0;
}
