#include <iostream>
using namespace std ;

template<class t>
class Node{
public:
    t data;
    Node<t>* next;
    // Constructor to initialize a node
    Node() : next(nullptr){}
    Node(t val)
    {
        data=val, next=nullptr;
    }
};
template<class t>
class LinkedList {
private:
    Node<t>* head ;
public:
    // Constructor to initialize an empty list
    LinkedList()  {
        head = nullptr;
    }
    // Destructor to clean up all nodes in the list
    ~LinkedList() {
        auto* temp = head;
        while (temp != nullptr) {
            Node<t>* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    // Insert a node at the front of the list
    void push_back(t val) {
        auto newNode = new Node<t>(val) ;
        if( head== nullptr){
            head=newNode ;
        }
        else{
            auto temp = head ;
            while( temp->next != nullptr )
                temp=temp->next ;
            temp->next = newNode ;
        }
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if( head->next== nullptr ){
            head= nullptr ;
            return;
        }
        auto* temp = head;
        while(temp->next->next != nullptr){
            temp=temp->next ;
        }
        temp->next = nullptr ;
    }
    // Display the list from the front to the rear
    void display() {
        auto* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main() {
    return 0;
}
