//Thuat toan dem so canh song song trong do thi.
//Do phuc tap O(n).

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countParallelEdges(const vector<pair<int, int>> &edges, int m) {
    int cnt = 0;
    //Su dung unordered_set de gia tri da ton tai se khong duoc them vao.
    unordered_set<int> visitedV;

    for (const auto &edge: edges) {
        int hash = edge.first * (m + 1) + edge.second;

        //'.second' la gia tri boolean (nhu iterator).
        if (!visitedV.insert(hash).second) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int m, n;
    cout << "Nhap so luong dinh:";
    cin >> m;
    cout << "Nhap so luong canh:";
    cin >> n;

    vector<pair<int, int>> edges;
    cout << "Nhap cac cap canh:";
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    int parallelEdges = countParallelEdges(edges, m);
    cout << parallelEdges << endl;

    return 0;
}
