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
    L.DeleteNodeAfter(2);
    L.PrintList();

    cout << "After inserting Node 5 at position 2" << endl;
    L.ListInsertAtPosition(5,2);
    L.PrintList();

    return 0;
    
} 