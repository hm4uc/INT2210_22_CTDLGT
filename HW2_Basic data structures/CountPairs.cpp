#include <iostream>

using namespace std;

const int maxx = 10000;
int main () {
    int n; cin >> n;
    int a[maxx];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] == a[i]) cnt++;
        }
    }
    cout << cnt << endl;
}
