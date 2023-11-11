/**
 * Cho một đồ thị gồm N đỉnh và M cạnh, các đính của đồ thị được đánh số từ 0 đến N−1.
 * Kiểm tra xem đồ thị này có chu trình hay không.
 */

//Dung DFS

#include<iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
int visited[1001];

int dfs(int u, int parent) {
    visited[u] = 1;
    for (int v: adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u))
                return 1;
        } else if (v != parent)
            return 1;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (dfs(1, -1))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
