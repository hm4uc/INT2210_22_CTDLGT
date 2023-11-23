#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int v, vector<vector<int>>& adj, set<int>& visited, int startEdge, int endEdge) {
    visited.insert(v);
    for (int neighbor : adj[v]) {
        if (neighbor != startEdge || v != endEdge) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adj, visited, startEdge, endEdge);
            }
        }
    }
}

int countBridgeEdges(int V, vector<vector<int>>& adj) {
    int count = 0;
    for (int u = 1; u <= V; ++u) {
        for (int v : adj[u]) {
            set<int> visitedBeforeRemoval;
            dfs(1, adj, visitedBeforeRemoval, u, v);

            // Nếu sau khi loại bỏ cạnh (u, v) đồ thị tăng số thành phần liên thông thì tăng biến đếm.
            if (visitedBeforeRemoval.size() < V) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int V, E;
    cout << "Nhap so dinh:";
    cin >> V;
    cout << "Nhap so canh:";
    cin >> E;

    vector<vector<int>> adj(V + 1);

    cout << "Nhap cac cap canh:";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int bridgeEdges = countBridgeEdges(V, adj);
    //Có cạnh cầu thì đồ thị không liên thông cạnh, và ngược lại.
    if (bridgeEdges > 0) {
        cout << "Đồ thị có cầu, đồ thị không liên thông cạnh." << endl;
    } else {
        cout << "Đồ thị liên thông cạnh." << endl;
    }

    return 0;
}
