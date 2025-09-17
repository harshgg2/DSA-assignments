#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class List {
    Node* head;
public:
    List() : head(nullptr) {}

    void insertFront(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    void insertBack(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* walk = head;
        while (walk->next) walk = walk->next;
        walk->next = n;
    }

    void insertAfter(int key, int x) {
        Node* walk = head;
        while (walk && walk->val != key) walk = walk->next;
        if (!walk) return;
        Node* n = new Node(x);
        n->next = walk->next;
        walk->next = n;
    }

    void insertBefore(int key, int x) {
        if (!head) return;
        if (head->val == key) { insertFront(x); return; }
        Node* walk = head;
        while (walk->next && walk->next->val != key) walk = walk->next;
        if (!walk->next) return;
        Node* n = new Node(x);
        n->next = walk->next;
        walk->next = n;
    }

    void deleteFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteBack() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* walk = head;
        while (walk->next->next) walk = walk->next;
        delete walk->next;
        walk->next = nullptr;
    }

    void deleteValue(int key) {
        if (!head) return;
        if (head->val == key) { deleteFront(); return; }
        Node* walk = head;
        while (walk->next && walk->next->val != key) walk = walk->next;
        if (!walk->next) return;
        Node* temp = walk->next;
        walk->next = temp->next;
        delete temp;
    }

    void search(int key) const {
        Node* walk = head;
        int pos = 1;
        while (walk) {
            if (walk->val == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            walk = walk->next;
            pos++;
        }
        cout << "Not Found\n";
    }

    void show() const {
        Node* walk = head;
        while (walk) {
            cout << walk->val << " ";
            walk = walk->next;
        }
        cout << "\n";
    }
};

int main() {
    List lst;
    int choice, x, key;
    while (true) {
        cin >> choice;
        if (choice == 1) { cin >> x; lst.insertFront(x); }
        else if (choice == 2) { cin >> x; lst.insertBack(x); }
        else if (choice == 3) { cin >> key >> x; lst.insertAfter(key, x); }
        else if (choice == 4) { cin >> key >> x; lst.insertBefore(key, x); }
        else if (choice == 5) lst.deleteFront();
        else if (choice == 6) lst.deleteBack();
        else if (choice == 7) { cin >> key; lst.deleteValue(key); }
        else if (choice == 8) { cin >> key; lst.search(key); }
        else if (choice == 9) lst.show();
        else break;
    }
}
