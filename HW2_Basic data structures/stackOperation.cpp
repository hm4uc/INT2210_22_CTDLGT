#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack <int> st;

void push(int x) {
    st.push(x);
}

void pop() {
    st.pop();
}

void print(stack <int> st) {
    vector<int> vt;
    while (!st.empty()) {
        vt.push_back(st.top());
        st.pop();
    }
    int l = vt.size();
    for (int i = l-1; i >= 0; i--) {
        cout << vt[i] << " ";
    }
}
int main () {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            push(x);
        }
        else if (s == "pop") {
            pop();
        }
    }
    print(st);
}
