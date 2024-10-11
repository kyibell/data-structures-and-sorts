// Node Class
class Node {
    // Data of the Node
    int data;
    // pointer pointing towards the next node
    Node* nextNode;

    // Default Constructor

    Node::Node() {
        data = 0;
        nextNode = nullptr;
    }
    // Initilized Constructor
    Node(int data) {
        this->data = data;
        this->nextNode = nullptr;
    }
};

class LinkedList {
    
};