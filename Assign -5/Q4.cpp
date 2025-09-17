#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class List {
    Node* start;
public:
    List() : start(nullptr) {}

    void pushBack(int v) {
        Node* temp = new Node(v);
        if (!start) {
            start = temp;
            return;
        }
        Node* walk = start;
        while (walk->next) walk = walk->next;
        walk->next = temp;
    }

    void reverseList() {
        Node* prev = nullptr;
        Node* curr = start;
        while (curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        start = prev;
    }

    void print() const {
        Node* p = start;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << "\n";
    }
};

int main() {
    List lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushBack(4);

    lst.reverseList();
    lst.print();
}
