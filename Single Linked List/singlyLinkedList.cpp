#include <iostream>
using namespace std;

// Node Class
class Node {
    public:
    int data; // Data of the Node
    Node* next;  // pointer pointing towards the next node

    // Default Constructor
    Node() {
        data = 0;
        next = nullptr;
    }
    // Initilized Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    // Declare a Head Node
    Node* head;
    
    public:
    // Default Constructor
    LinkedList() {
        this->head = nullptr;
    }

    // Insert at Head Funct
    void ListPrepend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    //Insert At Tail Funct
    void ListAppend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { // If list is empty, newNode is head
            head = newNode;
            return;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) { // while the list is not at the end
                temp = temp->next; // Goes to the end of the list
            }

            temp->next = newNode;
            newNode->next = nullptr;
        }
    }

    //Insert at Specific Position Function

    //Delete Node Function

    //Print List Funct
    void PrintList() {
        Node* currNode = head;
        cout << "Linked List is: " << endl;
        while (currNode != nullptr) {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
};



int main() {
    LinkedList L;

    L.ListAppend(3);
    L.ListPrepend(2);
    L.ListPrepend(1);
    L.ListAppend(4);

    L.PrintList();
}