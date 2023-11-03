#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;

    Item(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};

bool compare(Item it1, Item it2) {
    double x1 = (double) it1.value / it1.weight;
    double x2 = (double) it2.value / it2.weight;
    return x1 > x2;
}

double Knapsack(int W, vector<Item> &items, int n) {
    sort(items.begin(), items.end(), compare);
    double maxValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            maxValue += items[i].value;
        }
    }
    return maxValue;
}

int main() {
    int n;
    cin >> n;
    int W;
    cin >> W;
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        items.push_back({w, v});
    }
    cout << Knapsack(W, items, n);
}

