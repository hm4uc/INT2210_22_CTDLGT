/**
 * Cho một đồ thị vô hướng là một cây gồm n đỉnh. Tìm tất cả các đỉnh có thể được chọn làm gốc sao cho độ cao của cây là nhỏ nhất có thể.
 * In ra màn hình tất cả các đỉnh có thể được chọn làm gốc sao cho độ cao của cây là nhỏ nhất có thể theo thứ tự tăng dần.
 */

#include<iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxx = 1000;

vector<int> adj[maxx];
bool visited[maxx];
int dist[maxx];

void DFS(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dist[v] = dist[u] + 1;
            DFS(v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        dist[i] = 0;
        DFS(i);

        int treeHeight = dist[0];
        for (int i = 1; i < n; i++) {
            if (treeHeight < dist[i]) {
                treeHeight = dist[i];
            }
        }
        res.push_back(treeHeight);
    }

    int min_height = res[0];
    for (int i = 1; i < n; i++) {
        if (min_height > res[i]) {
            min_height = res[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (res[i] == min_height) {
            cout << i << " ";
        }
    }
    return 0;
}
