#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

void topologicalSort(vector<vector<int>>& graph, vector<int>& incomingDeg, vector<int>& res) {
    queue<int> q;
    for (int i = 0; i < graph.size(); i++) {
        if (incomingDeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u + 1);
        for(auto v : graph[u]) {
            incomingDeg[v]--;
            if (incomingDeg[v] == 0) {
                q.push(v);
            }
        }

    }
}
int main() {
    ifstream input("jobs.txt");
    ofstream output("jobs.out");

    int n, m;
    input >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> incomingDeg(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        graph[u - 1].push_back(v - 1);
        incomingDeg[v - 1]++;
    }

    vector<int> res;
    topologicalSort(graph, incomingDeg, res);
    for (auto node : res) {
        output << node << " ";
    }

    input.close();
    output.close();
    return 0;
}
