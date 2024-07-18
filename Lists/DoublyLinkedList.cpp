#include <iostream>
using namespace std ;

template<class t>
class Node{
public:
    t data;
    Node* next, *prev;
    // Constructor to initialize a node
    Node(t val) : data(val), next(nullptr), prev(nullptr) {}
};
template<class t>
class DoublyLinkedList {
private:
    Node<t>* head;
    Node<t>* tail;
public:
    // Constructor to initialize an empty list
    DoublyLinkedList()  {
        head(nullptr), tail(nullptr) ;
    }

    // Destructor to clean up all nodes in the list
    ~DoublyLinkedList() {
        Node<t>* current = head;
        while (current != nullptr) {
            Node<t>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert a node at the front of the list
    void insertFront(t val) {
        Node<t>* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert a node at the end of the list
    void insertRear(t val) {
        Node<t>* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a node from the front of the list
    void deleteFront() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        Node<t>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Delete a node from the end of the list
    void deleteRear() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node<t>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Display the list from the front to the rear
    void displayForward() {
        Node<t>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // Display the list from the rear to the front
    void displayBackward() {
        Node<t>* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << "\n";
    }
};
int main() {
    return 0;
}
