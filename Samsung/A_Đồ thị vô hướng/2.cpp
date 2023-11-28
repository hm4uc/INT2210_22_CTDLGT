#include <iostream>

using namespace std;

long long C(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return C(n - 1, k - 1) + C(n - 1, k);
}

long long countGraphs(int V, int E) {
    if (E < 0 || E > V * (V - 1) / 2) {
        return 0;  // Số lượng cạnh không hợp lệ
    }

    return C(V * (V - 1) / 2, E);
}

int main() {
    int V, E;
    cout << "Nhap so dinh (V): ";
    cin >> V;
    cout << "Nhap so canh (E): ";
    cin >> E;

    long long res = countGraphs(V, E);
    cout << "So do thi vo huong co " << V << " dinh va " << E << " canh la: " << res << endl;

    return 0;
}
