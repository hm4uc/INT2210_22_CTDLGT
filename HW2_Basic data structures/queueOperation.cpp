#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

void enqueue(int x) {
    q.push(x);
}

void dequeue() {
    q.pop();
}

int main () {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "enqueue") {
            int x; cin >> x;
            enqueue(x);
        }
        else if (s == "dequeue") {
            dequeue();
        }
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
