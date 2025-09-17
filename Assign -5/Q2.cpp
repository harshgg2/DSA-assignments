#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* link;
    Node(int v) : value(v), link(nullptr) {}
};

class List {
    Node* start;
public:
    List() : start(nullptr) {}

    void addBack(int v) {
        Node* temp = new Node(v);
        if (!start) {
            start = temp;
            return;
        }
        Node* walk = start;
        while (walk->link) walk = walk->link;
        walk->link = temp;
    }

    int removeAll(int key) {
        int removed = 0;

        // Handle head separately
        while (start && start->value == key) {
            Node* gone = start;
            start = start->link;
            delete gone;
            removed++;
        }

        // Handle rest
        Node* cur = start;
        while (cur && cur->link) {
            if (cur->link->value == key) {
                Node* gone = cur->link;
                cur->link = gone->link;
                delete gone;
                removed++;
            } else {
                cur = cur->link;
            }
        }
        return removed;
    }

    void show() const {
        for (Node* p = start; p; p = p->link) {
            cout << p->value << " ";
        }
        cout << "\n";
    }
};

int main() {
    List lst;
    lst.addBack(1);
    lst.addBack(2);
    lst.addBack(1);
    lst.addBack(2);
    lst.addBack(1);
    lst.addBack(3);
    lst.addBack(1);

    int total = lst.removeAll(1);
    cout << "Removed: " << total << "\n";

    lst.show();
}
