// Bubble Sort for Linked List

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
    // Find Node Funct.
    Node* FindNode(int data) {
        Node* currNode;
        currNode = head;

        while (currNode != nullptr) {
            if (currNode->data == data) {
                return currNode;
            }
            currNode = currNode->next;
        }
        return nullptr; // if not found return NULL
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

    void ListInsertAtPosition(int data, int position) {
        Node* newNode = new Node(data);

        if (position == 1) { // insertion at the head
            newNode->next = head;
            head = newNode;
            return;
        }

        int currPos = 1;
        Node* temp = head;

        while (temp != nullptr && currPos < position - 1) {
            temp = temp->next;
            currPos++;
        }

        if (temp == nullptr) {
            cout << "Could not insert, position is out of bounds." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next; // Insert temp at position
        temp->next = newNode;


    }

    // Delete Node Function
    void DeleteNodeAfter(int data) {
        Node* succNode;
        Node* currNode = FindNode(data);
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

    void swap(Node* a, Node* b) { // Swap function for nodes
        int temp = a->data; // just swapping the data, not the node themselves
        a->data = b->data;
        b->data = temp;
    }

    // Bubble Sort Funct
    
    void selectionsort(LinkedList L) {
        if (head == nullptr) { // if the list is empty
            return;
        }

        Node* currNode;
        for (currNode = head; currNode != nullptr; currNode = currNode->next) { 
            Node* minNode = currNode; // Assume currNode is the minNode

            for (Node* temp = currNode->next; temp != nullptr; temp = temp->next) {
                if (temp->data < minNode->data) { // if temp is lower then current minNode, minNode = temp
                    minNode = temp;
                }
            }
            swap(currNode, minNode); // swap the data values of minNode and currNode
        }
    }
};

int main() {

    LinkedList L;

    L.ListAppend(4);
    L.ListAppend(2);
    L.ListAppend(1);
    L.ListAppend(3);

    cout << "List before sort: " << endl;
    L.PrintList();
    cout << "List after sort: " << endl;
    L.selectionsort(L);
    L.PrintList();

    }

