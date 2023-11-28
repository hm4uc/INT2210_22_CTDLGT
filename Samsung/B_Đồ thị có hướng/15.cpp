#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(vector<vector<int>> &graph, vector<int> &indegree, vector<int> &result) {
    int n = graph.size();
    queue<int> q;

    //Đưa các đỉnh nguồn vào hàng đợi
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    //Duyệt qua tất cả các cạnh
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u); //Đánh nhãn cho đỉnh nguồn

        //Giảm bậc vào cho các đỉnh kề
        for (int neighbor: graph[u]) {
            indegree[neighbor]--;
            //Nếu bậc vào của đỉnh kề giảm về 0, thêm vào hàng đợi
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    vector<int> result;
    topologicalSort(graph, indegree, result);

    for (int u: result) {
        cout << u << " ";
    }

    return 0;
}
