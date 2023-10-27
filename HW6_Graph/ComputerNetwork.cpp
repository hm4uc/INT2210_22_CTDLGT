#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {};
};

struct Dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n, 0);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
    }

    int find_set(int u) {
        if (par[u] == u) {
            return u;
        }
        return par[u] = find_set(par[u]);
    }

    bool union_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) {
            return false;
        }
        par[v] = u;
        return true;
    }
} dsu;

int main() {
    ifstream input("connection.txt");
    ofstream output("connection.out");

    int n, m, totalW = 0;
    vector < Edge > edges;

    input >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        input >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    dsu.init(n);

    sort(edges.begin(), edges.end(), [](Edge& x, Edge& y) {
        if(x.w != y.w) {
            return x.w < y.w;
        }
        else return x.u > y.u;
    });

    vector<Edge> res;
    for (auto e : edges) {
        if (!dsu.union_set(e.u, e.v)) {
            continue;
        }
        totalW += e.w;
        res.push_back({e.u, e.v, e.w});
    }
    output << totalW << endl;
    for (int i = 0; i < res.size(); i++) {
        output << res[i].u << " " << res[i].v << " " << res[i].w << endl;
    }

    input.close();
    output.close();

    return 0;
}
