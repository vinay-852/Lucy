#include <iostream>
using namespace std;

// Linked list node template
template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor
    Node(T dat, Node* nex) {
        data = dat;
        next = nex;
    }
};

//Insertion
template <typename T>
void insert(int x, T data, Node<T>*& head, int position=0) {
    if (x == 0) {
        cout << "Insertion at head\n";
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
    } else if (x == 1) {
        if (position < 0) {
            cout << "Invalid position\n";
            return;
        }
        Node<T>* temp = head;
        for (int count = 0; count < position-1; count++) {
            if (temp->next == nullptr) {
                cout << "Position out of bounds\n";
                return;
            }
            temp = temp->next;
        }
        Node<T>* newNode = new Node<T>(data, temp->next);
        temp->next = newNode;
    } else {
        cout << "Invalid value for x\n";
    }
}

//Deletion
template <typename T>
void deleteNode(int x, Node<T>*& head, int position=0) {
    if (x == 0) {
        cout << "Deletion at head\n";
        Node<T>* temp = head;
        head = temp->next;
        delete temp;
    } else if (x == 1) {
        if (position < 0) {
            cout << "Invalid position\n";
            return;
        }
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        for (int count = 0; count < position; count++) {
            if (temp == nullptr) {
                cout << "Position out of bounds\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        if (prev != nullptr) {
            prev->next = temp->next;
        }
        delete temp;
    } else {
        cout << "Invalid value for x\n";
    }
}
int main() {
    Node<int>* head = nullptr;

    // Inserting nodes
    insert(0, 1, head); // Inserting 1 at head
    insert(1, 2, head, 1); // Inserting 2 at position 1
    insert(0, 3, head); // Inserting 3 at position 2

    // Deleting nodes
   // deleteNode(0, head); // Deleting node at head
    //deleteNode(1, head, 1); // Deleting node at position 1

    // Printing the list
    Node<int>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
