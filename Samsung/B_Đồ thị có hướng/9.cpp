#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

void Hierholzer(vector<vector<int> > adj) {
    unordered_map<int, int> mp;
    for (int i = 0; i < adj.size(); i++) {
        mp[i] = adj[i].size();
    }
    if (adj.empty()) {
        return;
    }
    stack<int> st;
    vector<int> circuit;
    st.push(0);
    int v = 0;
    while (!st.empty()) {
        if (mp[v]) {
            st.push(v);
            int next_v = adj[v].back();
            mp[v]--;
            adj[v].pop_back();
            v = next_v;
        } else {
            circuit.push_back(v);
            v = st.top();
            st.pop();
        }
    }
    for (int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i];
        if (i)
            cout << " -> ";
    }
}

int main() {
    int vertices, edges;
    cout << "Nhap so dinh:";
    cin >> vertices;
    cout << "Nhap so canh:";
    cin >> edges;
    vector<vector<int>> adj(vertices);

    cout << "Nhap cac cap canh (tu 0):";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << "Chu trinh Euler:";
    Hierholzer(adj);

    return 0;
}

