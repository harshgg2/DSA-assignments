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

    int getMiddle() {
        Node* slow = start;
        Node* fast = start;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ? slow->value : -1; // -1 if list empty
    }
};

int main() {
    List lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushBack(4);
    lst.pushBack(5);

    cout << "Middle: " << lst.getMiddle() << "\n";
}
