#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertionNode(Node*& tail, int element, int value) {
    if (tail == NULL) {
        Node* newNode = new Node(value);
        newNode->next = newNode;
        tail = newNode;
        return;
    }

    Node* curr = tail;
    do {
        if (curr->data == element) {
            Node* temp = new Node(value);
            temp->next = curr->next;
            curr->next = temp;
            if (curr == tail) tail = temp;
            return;
        }
        curr = curr->next;
    } while (curr != tail);

    cout << "Element " << element << " not found.\n";
}

void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);

    cout << "(head)\n";
}

void delElement(int element, Node*& tail) {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* prev = tail;
    Node* curr = tail->next;

    do {
        if (curr->data == element) {
            prev->next = curr->next;

            if (curr == tail && curr == tail->next) {
                tail = NULL; // only one node
            } else if (curr == tail) {
                tail = prev;
            }

            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << "Element " << element << " not found.\n";
}

Node* searchNode(Node* tail, int key) {
    if (tail == NULL) return NULL;

    Node* curr = tail->next;
    do {
        if (curr->data == key)
            return curr;
        curr = curr->next;
    } while (curr != tail->next);

    return NULL;
}

int main() {
    Node* tail = NULL;
    int choice, element, data, key;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Print\n4. Search\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element after which to insert: ";
            cin >> element;
            cout << "Enter data to insert: ";
            cin >> data;
            insertionNode(tail, element, data);
            break;

        case 2:
            cout << "Enter element to delete: ";
            cin >> element;
            delElement(element, tail);
            break;

        case 3:
            print(tail);
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            {
                Node* result = searchNode(tail, key);
                if (result)
                    cout << "Found node with value " << result->data << " at address " << result << endl;
                else
                    cout << "Element not found\n";
            }
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid option\n";
        }
    }
}
