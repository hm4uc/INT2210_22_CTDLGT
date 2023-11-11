#include<bits/stdc++.h>
using namespace std;

vector<int> tree[10001];
int maxDepth = -1;
int leafCount = 0;
bool visited[10001];

void dfs(int u, int depth) {
    visited[u] = true;
    if (depth > maxDepth) {
        maxDepth = depth;
        leafCount = 1;
    } else if (depth == maxDepth) {
        leafCount++;
    }
    for (int i = 0; i < tree[u].size(); i++) {
        if (!visited[tree[u][i]]) {
            dfs(tree[u][i], depth + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    cout << "Number of leaf nodes at maximum depth: " << leafCount << endl;
    return 0;
}

