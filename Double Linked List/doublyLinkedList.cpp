#include <iostream>
using namespace std;

// Node class
class Node {
    public:

    int data;
    Node* next; // next ptr
    Node* prev; // prev ptr
    
    // Default Constructor
    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    // Initilized Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

    public: 
    // Default Constructor
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    // Find Node Function
    Node* FindNode(int data) {
        Node* currNode;
        currNode = head;

        while (currNode != nullptr) {
            if (currNode->data == data) {
                return currNode;
            }
            currNode = currNode->next;
        }
        cout << "Node not found." << endl;
        return nullptr; 
    }
    // Prepend Function
    void ListPrepend(int data) {
        Node* newNode = new Node(data); // create new node
        if (head == nullptr) { // if list is empty
            head = newNode; 
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Append Function 
    void ListAppend(int data) {
        Node* newNode = new Node(data); // create a new node
        if (head == nullptr) { // check if list is empty
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at Position Function
    void ListInsertAtPosition(int data, int position) {
        Node* newNode = new Node(data);

        if (position == 1) { // insertion at head
            newNode->next = head;
            if (head == nullptr) { // if list is empty
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        int currPos = 1;
        Node* temp = head;
        while (temp != nullptr && currPos < position - 1) { // Find where the position of the node is
            temp = temp->next;
            currPos++;
        }

        if (temp == nullptr) { // check for out of bounds
            cout << "Could not insert, position is out of bounds." << endl;
            delete newNode;
            return;
        } 

        newNode->next = temp->next;
        newNode->prev = temp;
        
        if (temp->next != nullptr) { // If we're not inserting at the tail, check for temps next prev pointer
            temp->next->prev = newNode; // update the prev of temp's next with new node
        }

        temp->next = newNode; 
    }
    // Delete Node Function 
    void DeleteNodeAfter(int data) {
        Node* currNode = FindNode(data);
        Node* succNode = currNode->next;
        Node* predNode = currNode->prev;

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
            predNode = currNode->prev->prev;
            currNode->prev = predNode;

            if (succNode == nullptr) {
                tail = currNode;
            }
        }
    }
    

    // Print Node Function
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