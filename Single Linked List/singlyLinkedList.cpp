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
    // Declare a Head + Tail Node
    Node* head;
    Node* tail;

    public:
    // Default Constructor
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    // Insert at Head Funct
    void ListPrepend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { // If the list is empty
            head = newNode;
            tail = newNode;
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
            tail = newNode;
            return;
        }
        else { // else update tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    //Insert at Specific Position Function

    void ListInsertAfter(Node* currNode, Node* newNode) {
        if(head == nullptr) { // empty List
            head = newNode;
            tail = newNode;
        }
        else if (currNode = tail) { // insert after tail
            tail->next = newNode;
            tail = newNode;
        }
        else {
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
    }

    // Delete Node Function

    void DeleteNodeAfter(Node* currNode) {
        Node* succNode;
        if (currNode == nullptr && head != nullptr) {
            succNode = head->next;
            head = succNode;
            
            if (succNode == nullptr) {
                tail = nullptr;
            }
        }

        else if (currNode->next != nullptr) {
            succNode = currNode->next->next;
            currNode->next = succNode;

            if (succNode == nullptr) {
                tail = currNode;
            }
        }
    } 

    // Print specific Node
    void displayNode(Node* currNode) {
        cout << "Node: " << currNode->data << endl;
    }

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

    cout << "Original List: " << endl;
    L.PrintList(); 

    cout << "After Deleting Node 3" << endl;
    
} 