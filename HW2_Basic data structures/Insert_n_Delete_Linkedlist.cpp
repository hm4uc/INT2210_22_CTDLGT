#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node (int x) {
        value = x;
        next = NULL;
    }
};

void print(Node *head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

Node* pushFront(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    head->next = newNode->next;
    return head;
}

Node* insertNode(Node* head, int k, int x) {
    if (k == 0) {
        head = pushFront(head, x);
    }
    else {
        Node* newNode = new Node(x);
        Node* temp = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node* deleteNode(Node* head, int k) {
    if (k == 0) {
        Node* d = head;
        head = head->next;
        delete d;
        return head;
    }
    Node *temp = head;
    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }
    Node* d = temp->next;
    temp->next = temp->next->next;
    delete d;
    return head;
}
int main () {
    int n; cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "insert") {
            int k, x;
            cin >> k >> x;
            head = insertNode(head, k ,x);
        }
        else if (s == "delete") {
            int k;
            cin >> k;
            head = deleteNode(head, k);
        }
    }
    print(head);
    return 0;
}
