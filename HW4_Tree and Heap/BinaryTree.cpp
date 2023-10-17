#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int x) {
        value = x;
        left = NULL;
        right = NULL;
    }
};

int getDepth(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

void preorderTraversal(Node* root, vector<int>& res) {
    if (root == NULL) {
        return;
    }
    res.push_back(root->value);
    preorderTraversal(root->left, res);
    preorderTraversal(root->right, res);
}

void postorderTraversal(Node* root, vector<int>& res) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left, res);
    postorderTraversal(root->right, res);
    res.push_back(root->value);
}

bool isBinaryTree(Node* root, vector<int>& res) {
    if (root == NULL) {
        return true;
    }
    if (!isBinaryTree(root->left, res)) {
        return false;
    }
    res.push_back(root->value);
    if (!isBinaryTree(root->right, res)) {
        return false;
    }
    return true;
}
int main () {
    int n, m;
    cin >> n >> m;

    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node(i+1);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (nodes[u-1]->left == NULL) {
            nodes[u-1]->left = nodes[v-1];
        } else {
            nodes[u-1]->right = nodes[v-1];
        }
    }

    Node* root = nodes[0];

    int depth = getDepth(root);
    cout << depth << endl;

    vector<int> preorderRes;
    preorderTraversal(root, preorderRes);
    for (int ans:preorderRes) {
        cout << ans << " ";
    }
    cout << endl;

    vector<int> postorderRes;
    postorderTraversal(root, postorderRes);
    for (int ans:postorderRes) {
        cout << ans << " ";
    }
    cout << endl;

    vector<int> inorderRes;
    bool isBinary = isBinaryTree(root, inorderRes);
    if (isBinary) {
        for (int ans:inorderRes) {
            cout << ans << " ";
        }
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
        }

    for (Node* node:nodes) {
        delete node;
    }
    return 0;
}
