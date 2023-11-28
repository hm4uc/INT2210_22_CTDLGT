#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &st, vector<int> adj[]) {
    visited[v] = true;
    for (int i: adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, st, adj);
        }
    }
    st.push(v);
}

stack<int> topologicalSort(vector<int> adj[], int v) {
    stack<int> st;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, st, adj);
        }
    }
    return st;
}

bool hamiltonPath(vector<int> adj[], int n) {
    stack<int> order = topologicalSort(adj, n);
    vector<bool> visited(n, false);

    while (!order.empty()) {
        int v = order.top();
        order.pop();

        //Đỉnh đã được thăm thì không tồn tại đường đi
        if (visited[v]) {
            return false;
        }
        visited[v] = true;

        //Kiểm tra có cạnh nối từ đỉnh này sang đỉnh tiếp theo hay không
        if (!order.empty() && find(adj[v].begin(), adj[v].end(), order.top()) == adj[v].end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    if (hamiltonPath(adj, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
