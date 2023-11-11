//In ra trong so cua cay khung nho nhat

//Dung Prim

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxx = 10000;

struct Edge {
    int to, weight;
    Edge(int _to, int _weight) {
        to = _to;
        weight = _weight;
    }
};

int n, m;
vector<Edge> graph[maxx];
bool visited[maxx];

long long prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    int minWeight = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        minWeight += w;
        visited[u] = true;

        for (Edge edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    return minWeight;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].emplace_back(v, c);
        graph[v].emplace_back(u, c);
    }

    long long minCost = prim();
    cout << minCost << endl;

    return 0;
}
