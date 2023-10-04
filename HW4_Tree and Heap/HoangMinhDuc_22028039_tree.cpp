#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* nextChild;

public:
    Node() : data(0), fatherNode(NULL), firstChild(NULL), nextChild(NULL) {}
// Các hàm khởi tạo khác nếu cần thiết

    //Constructor
    Node(int value, Node* father) {
        this->data = value;
        fatherNode = father;
        firstChild = NULL;
        nextChild = NULL;
    }
    //Đếm số con của 1 Node
    //Áp dụng cho hàm isBinarySearchTree và hàm findMaxChild
    int countChild()  {
        int cnt = 0;
        Node* temp = firstChild;
        while (temp != NULL) {
            cnt++;
            temp = temp->nextChild;
        }
        return cnt;
    }

    bool isBSTNode() {
        if (countChild() > 2) {
            return false;
        } else if (countChild() == 2) {
            if (data < firstChild->data || data > firstChild->nextChild->data) {
                return false;
            }
        }
        return true;
    }

    bool isHeapNode(){
        if (firstChild == NULL) {
            return true;
        }
        Node* temp = firstChild;
        while (temp) {
            if (data < temp->data) {
                return false;
            }
            temp = temp->nextChild;
        }
        return true;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        root = NULL;
    }

    // Các hàm khởi tạo khác nếu cần thiết
    Node* getRoot() {
        return root;
    }

    Tree(int value) {
        root = new Node(value, NULL);
    }

    //Tìm Node có giá trị là value trong Tree
    Node* findNode(Node* node, int value) {
        if (node != NULL) {
            if (node->data == value) {
                return node;
            }
            Node* temp = findNode(node->firstChild, value);
            if (temp != NULL) {
                return temp;
            }
            temp = findNode(node->nextChild, value);
            if (temp != NULL) {
                return temp;
            }
        }
        return NULL;
    }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        if (root == NULL) {
            root = new Node(father, NULL);
        }
        Node* temp = findNode(root, father);
        if (temp == NULL) {
            return false;
        }
        Node* newNode = new Node(data, temp);
        if (temp->firstChild == NULL) {
            temp->firstChild = newNode;
        } else {
            if (temp->firstChild->data == data) {
                return false;
            }
            while (temp->firstChild->nextChild != NULL) {
                if (temp->firstChild->data == data) {
                    return false;
                }
                temp->firstChild = temp->firstChild->nextChild;
            }
            if (temp->firstChild -> data == data) {
                return false;
            }
            temp->firstChild->nextChild = newNode;
        }
        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    void deleteNode(Node* d, Node* temp, int& cnt) {
        if (temp == NULL) {
            return;
        } else {
            cnt++;
        }
        deleteNode(d, temp->firstChild, cnt);
        if (temp != d) {
            deleteNode(d, temp->nextChild, cnt);
        }
        delete temp;

    }
    int remove(int data) {
        Node* d = findNode(root, data);
        Node* father = d->fatherNode;
        Node* temp = father->firstChild;

        if (temp == d) {
            father->firstChild = d->nextChild;
        } else {
            while (temp->nextChild != d) {
                temp = temp->nextChild;
            }
            temp->nextChild = d->nextChild;
        }
        if (d == NULL) {
            return 0;
        }
        int cnt = 0;
        deleteNode(d, d, cnt);
        return cnt;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preorder(node->firstChild);
        preorder(node->nextChild);
    }
    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node* node) {
        if (node == NULL) {
            return;
        }
        postorder(node -> firstChild);
        if (node->firstChild != NULL) {
            postorder(node ->firstChild -> nextChild);
        }
        cout << node -> data << " ";
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        if (root == NULL) return false;
        Node* temp = root;
        while (temp) {
            if (temp -> countChild() > 2) {
                return false;
            }
            while (temp -> firstChild) {
                temp = temp -> firstChild;
                if (temp -> countChild() > 2) {
                    return false;
                }
            }
            if (temp -> nextChild) {
                temp = temp -> nextChild;
                if (temp -> countChild() > 2) {
                    return false;
                }
            }
            if (temp->firstChild == NULL){
                while (temp->nextChild == NULL && temp != root) {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextChild;
            }
        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
    if (root == NULL) return false;
        Node* temp = root;
        while (temp) {
            if (temp -> isBSTNode() == false) return false;
            while (temp -> firstChild) {
                temp = temp -> firstChild;
                if (temp -> isBSTNode() == false) return false;
            }
            if (temp -> nextChild) {
                temp = temp -> nextChild;
                if (temp -> isBSTNode() == false) return false;
            }
            // if no child -> leaf node -> traverse up -> go to next
            if (temp->firstChild == NULL){
                while (temp->nextChild == NULL && temp != root) {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextChild;
            }
        }
        return true;
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
    if (root == NULL) {
        return false;
    }
        Node* temp = root;
        while (temp) {
            while (temp -> firstChild) {
                temp = temp -> firstChild;
                if (temp -> isHeapNode() == false) {
                    return false;
                }
            }
            if (temp -> nextChild) {
                temp = temp -> nextChild;
                if (temp -> isHeapNode() == false) {
                    return false;
                }
            }
            if (temp->firstChild == NULL) {
                while (temp->nextChild == NULL && temp != root) {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextChild;
            }
        }
        return true;
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder(Node * node) {
        if (isBinaryTree() == false) {
            cout << "Not a binary tree" << endl;
            return;
        }
        if (node == NULL) {
            return;
        }
        inorder(node -> firstChild);
        cout << node -> data << " ";
        if (node->firstChild) {
            inorder(node -> firstChild -> nextChild);
        }
    }

    // Hàm trả về độ cao của cây
    int height() {
        if (root == NULL) {
            return -1;
        }
        int d = 0, h = 0;
        Node* temp = root;
        while (temp) {
            while (temp -> firstChild) {
                temp = temp -> firstChild;
            }
            d = depth(temp->data);
            if (d > h) {
                h = d;
            }
            if (temp -> nextChild) {
                temp = temp -> nextChild;
            }
            if (temp -> firstChild == NULL) {
                while (temp -> nextChild == NULL && temp != root) {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextChild;
            }
        }
        return h;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node* node = findNode(root, data);
        if (node == NULL) {
            return -1;
        }
        int d = 0;
        while (node -> fatherNode) {
            node = node -> fatherNode;
            d++;
        }
        return d;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        if (root == NULL) {
            return 0;
        }
        int leaves = 0;
        Node* temp = root;
        while (temp != NULL) {
            while (temp -> firstChild) {
                temp = temp -> firstChild;
            }
            leaves ++;

            if (temp -> nextChild != NULL) {
                temp = temp -> nextChild;
            }
            if (temp -> firstChild == NULL){
                while (temp -> nextChild == NULL && temp != root) {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextChild;
            }
        }
        return leaves;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {
        Node* temp = root;
        int maxx = temp->data;
        while (temp) {
            if (temp->data > maxx) {
                maxx = temp->data;
            }
            while (temp->firstChild) {
                temp = temp->firstChild;
                if (temp->data > maxx) {
                    maxx = temp->data;
                }
            }
            if (temp->nextChild) {
                temp = temp->nextChild;
                if (temp->data > maxx) {
                    maxx = temp->data;
                }
            }
            if (temp->firstChild == NULL) {
                while (temp->nextChild == NULL && temp != root) {
                    temp = temp->fatherNode;
                }
                temp = temp->nextChild;
            }
        }
        return maxx;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        Node* temp = root;
        int maxx = 0;
        while (temp != NULL) {
            if (temp->countChild() > maxx) {
                maxx = temp->countChild();
            }
            while (temp -> firstChild) {
                temp = temp -> firstChild;
                if (temp->countChild() > maxx) {
                    maxx = temp->countChild();
                }
            }
            if (temp -> nextChild) {
                temp = temp -> nextChild;
                if (temp->countChild() > maxx) {
                    maxx = temp->countChild();
                }
            }
            if (temp -> firstChild == NULL) {
                while (temp ->nextChild == NULL && temp != root) {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextChild;
            }
        }
        return maxx;
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây
    Tree* tree = new Tree();
    for (int i = 0; i < 30; i++) {
        tree->insert(i+1, i+2);
    }
    cout << tree->getRoot()->countChild() << endl;
    tree->preorder(tree->getRoot()); cout << endl;
    tree->postorder(tree->getRoot()); cout << endl;
    tree->inorder(tree->getRoot()); cout << endl;
    tree->remove(10);
    cout << tree->isBinaryTree() << endl;
    cout << tree->isBinarySearchTree() << endl;
    cout << tree->isMaxHeapTree() << endl;
    cout << tree->depth(5) << endl;
    cout << tree->height() << endl;
    cout << tree->numOfLeaves() << endl;

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    Tree* tree1 = new Tree();
    tree1->insert(3, 1);
    tree1->insert(3, 5);
    tree1->insert(1, 2);
    tree1->insert(5, 4);
    cout << tree1->isBinarySearchTree() << endl;
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    Tree* tree2 = new Tree();
    tree2->insert(5, 4);
    tree2->insert(5, 3);
    tree2->insert(4, 2);
    tree2->insert(4, 1);
    tree2->insert(3, 0);
    cout << tree2->isMaxHeapTree() << endl;
}

