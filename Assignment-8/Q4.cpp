#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBSTUtil(Node* r, long long minV, long long maxV) {
        if(!r) return true;
        if(r->data <= minV || r->data >= maxV) return false;
        return isBSTUtil(r->left, minV, r->data) && isBSTUtil(r->right, r->data, maxV);
    }
    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);
    Solution s;
    cout<<s.isBST(root)<<"\n";
}
