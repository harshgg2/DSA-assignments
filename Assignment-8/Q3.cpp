#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root = NULL;

    Node* insert(Node* r, int v) {
        if(!r) return new Node(v);
        if(v < r->data) r->left = insert(r->left, v);
        else if(v > r->data) r->right = insert(r->right, v);
        return r;
    }

    void insert(int v) { root = insert(root, v); }

    Node* minNode(Node* r) {
        while(r->left) r = r->left;
        return r;
    }

    Node* deleteNode(Node* r, int v) {
        if(!r) return r;
        if(v < r->data) r->left = deleteNode(r->left, v);
        else if(v > r->data) r->right = deleteNode(r->right, v);
        else {
            if(!r->left) return r->right;
            else if(!r->right) return r->left;
            Node* t = minNode(r->right);
            r->data = t->data;
            r->right = deleteNode(r->right, t->data);
        }
        return r;
    }

    void del(int v) { root = deleteNode(root, v); }

    int maxDepth(Node* r) {
        if(!r) return 0;
        return 1 + max(maxDepth(r->left), maxDepth(r->right));
    }

    int minDepth(Node* r) {
        if(!r) return 0;
        if(!r->left) return 1 + minDepth(r->right);
        if(!r->right) return 1 + minDepth(r->left);
        return 1 + min(minDepth(r->left), minDepth(r->right));
    }
};

int main() {
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(3);
    b.insert(7);
    b.insert(12);
    b.insert(20);
    b.del(10);
    cout<<b.maxDepth(b.root)<<"\n";
    cout<<b.minDepth(b.root)<<"\n";
}
