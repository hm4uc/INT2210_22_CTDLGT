//Kiem tra chu trinh Euler va chu trinh Hamilton

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void dfs(int v, bool visited[], vector<int> adj[]) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[adj[v][i]]) {
            dfs(adj[v][i], visited, adj);
        }
    }
}

//Kiem tra tinh lien thong
bool isConnected(vector<int> adj[], int V) {
    bool visited[V];
    memset(visited, false, sizeof(visited));
    int i;
    for (i = 0; i < V; i++)
        if (!adj[i].empty()) {
            break;
        }
    if (i == V) {
        return true;
    }
    dfs(i, visited, adj);
    for (i = 0; i < V; i++) {
        if (!visited[i] && !adj[i].empty()) {
            return false;
        }
    }
    return true;
}

bool isCyclicUtil(int v, bool visited[], int parent, vector<int> adj[]) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[adj[v][i]]) {
            if (isCyclicUtil(adj[v][i], visited, v, adj)) {
                return true;
            }
        } else if (adj[v][i] != parent) {
            return true;
        }
    }
    return false;
}

int isEulerCircuit(vector<int> adj[], int V) {
    if (!isConnected(adj, V)) {
        return 0;
    }
    int odd = 0;
    for (int i = 0; i < V; i++) {
        if (adj[i].size() & 1) {
            odd++;
        }
    }
    if (odd > 2) {
        return 0;
    }
    if (odd) {
        return 1;
    } else {
        return 2;
    }
}

bool isHamiltonCircuit(vector<int> adj[], int V) {
    if (!isConnected(adj, V)) {
        return false;
    }

    int degree[V];
    for (int i = 0; i < V; i++) {
        degree[i] = adj[i].size();
    }

    for (int i = 0; i < V; i++) {
        if (degree[i] < V / 2) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap so luong canh:";
    cin >> n;
    vector<int> adj[n];
    cout << "Nhap cac cap canh:";
    for (int i = 0; i < n; i++) {
        int u, v;
        char c;
        cin >> u >> c >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isEulerCircuit(adj, n) == 0) {
        cout << "Khong co chu trinh Euler\n";
    } else if (isEulerCircuit(adj, n) == 1) {
        cout << "Co duong di Euler\n";
    } else {
        cout << "Co chu trinh Euler\n";
    }

    if (isHamiltonCircuit(adj, n)) {
        cout << "Co chu trinh Hamilton\n";
    } else {
        cout << "Khong co chu trinh Hamilton\n";
    }

    return 0;
}