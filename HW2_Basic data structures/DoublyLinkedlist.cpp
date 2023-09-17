#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
    Node (int x) {
        value = x;
        prev = NULL;
        next = NULL;
    }
};

Node* pushBack(Node* head, int x) {
    Node* newNode = new Node(x);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int sumEqualZero(Node* head) {
    int cnt = 0;
    Node* temp = head->next;
    while(temp->next != NULL) {
        if (temp->prev->value + temp->value + temp->next->value == 0) cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main () {
    int n; cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        head = pushBack(head, x);
    }
    cout << sumEqualZero(head);
}
